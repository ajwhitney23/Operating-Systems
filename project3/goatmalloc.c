#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>
#include "goatmalloc.h"

#define HEADER_SIZE (int) sizeof(struct __node_t)

void* _arena_start;
size_t total_size;
struct __node_t *header_list;

int statusno = ERR_UNINITIALIZED;

/*
 * initalizes the arena based on size passed in, rounds to nearest page size.
 */
extern int init(size_t size) {
    if ((int)size <= 0) {
        return ERR_BAD_ARGUMENTS;
    }

    printf("Initializing arena: \n");
    printf("...requested size %d bytes\n", (int) size);
    printf("...pagesize is %d bytes\n", getpagesize());
    printf("...adjusting size with page boundaries\n");

    int num_pages = (int) ceil((double)size/(double)getpagesize());
    total_size = num_pages * getpagesize();

    printf("...adjusted size is %d bytes\n", (int) total_size);
    printf("...mapping arena with mmap()\n");

    int fd=open("/dev/zero",O_RDWR);
    _arena_start = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    printf("...arena starts at %p\n", _arena_start);
    printf("...arena ends at %p\n", _arena_start + total_size);

    struct __node_t *header = _arena_start;
    header->size = total_size - HEADER_SIZE;
    header->is_free = 1;
    header->bwd = NULL;
    header->fwd = NULL;
    header_list = header;

    printf("...initalizing header for inital free chunk\n");
    printf("...header size is %d\n", HEADER_SIZE);

    statusno = 0;

    return total_size;
}

/*
 * destorys the allocated memeory
 */
extern int destroy() {
    if(_arena_start == NULL) {
        return ERR_UNINITIALIZED;
    }

    printf("Destorying Arena: \n");
    printf("...unmapping arena with munmap()\n");

    munmap(_arena_start, total_size);
    _arena_start = NULL;
    header_list = NULL;

    statusno = ERR_UNINITIALIZED;
    return 0;   
}

/*
 *  allocates memory of passed in parameter inside of the arena.
 *  returns the pointer to the allocated memeory, or null if arena isn't inialized or out of memory
 */
extern void* walloc(size_t size) {
    struct __node_t *current = header_list;

    if(statusno == ERR_UNINITIALIZED) {
        return NULL;
    }

    while(current != NULL) {
        if(current->is_free == 1) {
            size_t free_size = current->size;
            int is_equal_gt = (int)free_size >= (int)size;
            int is_gt = (int)free_size > (int)size + HEADER_SIZE;
            if(is_equal_gt) {
                current->size = !is_gt * (int)free_size + is_gt * size;
                current->is_free = 0;
            }
            if(is_gt) {
                struct __node_t *free_header = (void*)current + HEADER_SIZE + size;
                free_header->is_free = 1;
                free_header->size = (int)free_size - size - HEADER_SIZE;
                free_header->fwd = current->fwd;
                current->fwd = free_header;
                free_header->bwd = current;
            }
            if(is_equal_gt) {
                void* rtn_ptr = (void*)current + HEADER_SIZE;
                return rtn_ptr;
            }
        }
        current=current->fwd;
    }
    statusno = ERR_OUT_OF_MEMORY;
    return NULL;
}

/*
 *  free's the memory at the location from the pointer
 *  sets error messages if the memory isn't initalized or if the call failed
 */
extern void wfree(void *ptr) {
    struct __node_t *current = header_list;

    if(statusno == ERR_UNINITIALIZED) {
        return;
    }

    while(current != NULL) {
        if(ptr-HEADER_SIZE == (void*)current && current->is_free == 0) {
            struct __node_t *last = current->bwd;
            struct __node_t *next = current->fwd;

            if(last != NULL && last->is_free) {
                last->fwd = current->fwd;
                if(current->fwd != NULL) {
                    current->fwd->bwd = last;
                }
                last->size = (int)last->size + (int)current->size + HEADER_SIZE;
                current = (void*)last;
            }
            if(next != NULL && next->is_free) {
                current->fwd = next->fwd;
                if(next->fwd != NULL) {
                    next->fwd->bwd = current;
                }
                current->size = (int) current->size + (int)next->size + HEADER_SIZE;
            }
            current->is_free = 1;
            return;
        }
        current=current->fwd;
    }

    statusno = ERR_CALL_FAILED;
    return;
}

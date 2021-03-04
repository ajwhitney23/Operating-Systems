Author:				Andrew Whitney, Nathan Bargman
Date:				      02/23/21
Version:			      V1
Project ID:			      Project 3
CS Class:			      CS3013
Programming Language:		C
OS/Hardware dependencies:	Ubuntu 16.04

Problem Description:		Exploring memory virtualization through a simulation.	

Program Assumptions 
      and Restrictions:		Run on Ubuntu 16.04, gcc utilizes -lm for goatmalloc.c to for math.h include

Implementation Details:
	Data			int, char*, size_t, struct __node_t
	Variables		_arena_start, statusno, header_list 
	Algorithm		while loops (for linked list)

How to build the program:   make all to build goatmalloc binary
                            make clean to remove goatmalloc binary
                            

Program Source:		goatmalloc.c, goatmalloc.h, test_goatmalloc.c

Additional Files:		output.txt, README.txt, ajwhitney.docx, nmbargman.docx, Makefile, output_ref.txt

Results:                reference output.txt for full output from program running tests.

      Sample:
            Initializing arena: 
            ...requested size 1 bytes
            ...pagesize is 4096 bytes
            ...adjusting size with page boundaries
            ...adjusted size is 4096 bytes
            ...mapping arena with mmap()
            ...arena starts at 0x7fbe9aee5000
            ...arena ends at 0x7fbe9aee6000
            ...initalizing header for inital free chunk
            ...header size is 32
            Destorying Arena: 
            ...unmapping arena with munmap()

Test Procedures:	
                  output to terminal:

                  make clean
                  make
                  ./goatmalloc

                  output to specified file [filename]

                  make clean
                  make
                  ./goatmalloc > [filename]


Test Data:		passes all tests

References:		CS3013 Lectures
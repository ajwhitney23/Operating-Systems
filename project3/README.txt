Author:				Andrew Whitney, Nathan Bargman
Date:				02/23/21
Version:			V1
Project ID:			Project 3
CS Class:			CS3013
Programming Language:		C
OS/Hardware dependencies:	Ubuntu 16.04

Problem Description:		Exploring memory virtualization through a simulation.	

Program Assumptions 
      and Restrictions:		TODO

Implementation Details:
	Data			int, char*, size_t, struct __node_t
	Variables		N/A 
	Algorithm		for loops and while loops

How to build the program:   make all to build goatmalloc binary
                            make clean to remove goatmalloc binary
                            

Program Source:		goatmalloc.c, goatmalloc.h, test_goatmalloc.c

Additional Files:		output.txt, REAME.txt, ajwhitney.docx, nmbargman.docx, Makefile, output_ref.txt

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

Test Procedures:	make clean
                    make
                    ./goatmalloc

Test Data:			TODO

References:			CS3013 Lectures

STILL TODO:
find out what binary should be called
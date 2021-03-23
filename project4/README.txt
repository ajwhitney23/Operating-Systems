Author:				Andrew Whitney, Nathan Bargman
Date:				      03/18/21
Version:			      V1.1
Project ID:			      Project 4
CS Class:			      CS3013
Programming Language:		C
OS/Hardware dependencies:	Ubuntu 16.04

Problem Description:		Exploring concurrency through threads, mutual exclusion, conditions and semaphores.

Program Assumptions 
      and Restrictions:		Run on Ubuntu 16.04, gcc utilizes -lpthread for threads

Implementation Details:
	Data			int, char*, struct worker, struct package, pthread_t, pthread_mutex, pthread_cond, sem_t
	Variables		
	Algorithm		while loops, for loops

How to build the program:   make all to build p4 binary
                            make clean to remove p4 binary
                            

Program Source:		main.c, shipping.c, summer.c, shipping.h, names.txt, things.txt, seed.txt

Additional Files:		README.txt, ajwhitney.docx, nmbargman.docx, Makefile, problem1_explanation.txt, problem2_explanation.txt, [seed]_output.txt

Additional Notes:       Problem 2 Takes a while to run to prevent deadlocks

Results: reference [seed]_output.txt for output of each problem
            run program with debug [1] for more information
            

Procedures:	
                  for all:
                        set seed.txt to whatever desired seed is (e.g. 12345);
      
                  run both problems no debug:

                  make clean
                  make
                  ./p4 0
                  OR
                  make clean 
                  make
                  ./p4

                  run both problems with debug:

                  make clean
                  make
                  ./p4 1

                  running one or other problem w or w/o debug
                  make clean
                  make
                  ./p4 [debug] [problem]
                        debug: 0 for no, 1 for yes
                        problem: 1 for problem 1, 2 for problem 2

References:		CS3013 Lectures
                  Allen Downe, The Little Book of Semaphores [https://open.umn.edu/opentextbooks/textbooks/83]

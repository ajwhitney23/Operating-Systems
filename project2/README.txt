Author:				Andrew Whitney, Nathan Bargman
Date:				02/19/2021
Version:			V1
Project ID:			Project 2
CS Class:			CS3013
Programming Language:		C
OS/Hardware dependencies:	Ubuntu 16.04

Problem Description:		Exploring how the os manages tasks and processes.	

Program Assumptions 
      and Restrictions:		

Implementation Details:
	Data			ints, timespec, char*, char**, job struct (linked list of simulated jobs)
	Variables		N/A 
	Algorithm		for loops and while loops

How to build the program:   make all to build scheduler binary
                            make scheduler to build scheduler
                            make clean to remove scheduler binary
                            

Program Source:			scheduler.c

Additional Files:		test/*, run_tests.sh, TODO

Results:

Test Procedures:		run_tests.sh 

Test Data:			.in files with  a list of jobs with simulated length.  Each job broken up with newline

References:			CS3013 Lectures, Linux Man Pages (https://linux.die.net/man/)
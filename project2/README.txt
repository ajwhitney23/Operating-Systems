Author:				Andrew Whitney, Nathan Bargman
Date:				02/19/2021
Version:			V1
Project ID:			Project 2
CS Class:			CS3013
Programming Language:		C
OS/Hardware dependencies:	Ubuntu 16.04

Problem Description:		Exploring how the os manages tasks and processes.	

Program Assumptions 
      and Restrictions:		FIFO, SJF and RR are entered correctly in commandline arguments. ".in" files are only one integer per line.

Implementation Details:
	Data			ints, char*, job struct (linked list of simulated jobs)
	Variables		N/A 
	Algorithm		for loops and while loops, modified bubble sort algorithm

How to build the program:   make all to build scheduler binary
                            make scheduler to build scheduler
                            make clean to remove scheduler binary
                            

Program Source:			scheduler.c

Additional Files:		test/*, run_tests.sh, workload_[1-5].in

Results:

./scheduler RR workload_1.in 3
Execution trace with RR:
Job 0 ran for: 3
Job 1 ran for: 3
Job 2 ran for: 3
Job 3 ran for: 3
Job 4 ran for: 3
End of execution with RR.
Begin analyzing RR:
Job 0 -- Response time: 0  Turnaround: 3  Wait: 0
Job 1 -- Response time: 3  Turnaround: 6  Wait: 3
Job 2 -- Response time: 6  Turnaround: 9  Wait: 6
Job 3 -- Response time: 9  Turnaround: 12  Wait: 9
Job 4 -- Response time: 12  Turnaround: 15  Wait: 12
Average -- Response: 6.00  Turnaround 9.00  Wait 6.00
End analyzing RR.

./scheduler FIFO workload_2.in 0
Execution trace with FIFO:
Job 0 ran for: 1000
Job 1 ran for: 100
Job 2 ran for: 1
Job 3 ran for: 1
Job 4 ran for: 1
Job 5 ran for: 1
Job 6 ran for: 1
Job 7 ran for: 1
Job 8 ran for: 1
Job 9 ran for: 1
Job 10 ran for: 1
Job 11 ran for: 1
Job 12 ran for: 1
Job 13 ran for: 1
End of execution with FIFO.
Begin analyzing FIFO:
Job 0 -- Response time: 0  Turnaround: 1000  Wait: 0
Job 1 -- Response time: 1000  Turnaround: 1100  Wait: 1000
Job 2 -- Response time: 1100  Turnaround: 1101  Wait: 1100
Job 3 -- Response time: 1101  Turnaround: 1102  Wait: 1101
Job 4 -- Response time: 1102  Turnaround: 1103  Wait: 1102
Job 5 -- Response time: 1103  Turnaround: 1104  Wait: 1103
Job 6 -- Response time: 1104  Turnaround: 1105  Wait: 1104
Job 7 -- Response time: 1105  Turnaround: 1106  Wait: 1105
Job 8 -- Response time: 1106  Turnaround: 1107  Wait: 1106
Job 9 -- Response time: 1107  Turnaround: 1108  Wait: 1107
Job 10 -- Response time: 1108  Turnaround: 1109  Wait: 1108
Job 11 -- Response time: 1109  Turnaround: 1110  Wait: 1109
Job 12 -- Response time: 1110  Turnaround: 1111  Wait: 1110
Job 13 -- Response time: 1111  Turnaround: 1112  Wait: 1111
Average -- Response: 1019.00  Turnaround 1098.43  Wait 1019.00
End analyzing FIFO.

./scheduler SJF workload_2.in 0
Execution trace with SJF:
Job 2 ran for: 1
Job 3 ran for: 1
Job 4 ran for: 1
Job 5 ran for: 1
Job 6 ran for: 1
Job 7 ran for: 1
Job 8 ran for: 1
Job 9 ran for: 1
Job 10 ran for: 1
Job 11 ran for: 1
Job 12 ran for: 1
Job 13 ran for: 1
Job 1 ran for: 100
Job 0 ran for: 1000
End of execution with SJF.
Begin analyzing SJF:
Job 2 -- Response time: 0  Turnaround: 1  Wait: 0
Job 3 -- Response time: 1  Turnaround: 2  Wait: 1
Job 4 -- Response time: 2  Turnaround: 3  Wait: 2
Job 5 -- Response time: 3  Turnaround: 4  Wait: 3
Job 6 -- Response time: 4  Turnaround: 5  Wait: 4
Job 7 -- Response time: 5  Turnaround: 6  Wait: 5
Job 8 -- Response time: 6  Turnaround: 7  Wait: 6
Job 9 -- Response time: 7  Turnaround: 8  Wait: 7
Job 10 -- Response time: 8  Turnaround: 9  Wait: 8
Job 11 -- Response time: 9  Turnaround: 10  Wait: 9
Job 12 -- Response time: 10  Turnaround: 11  Wait: 10
Job 13 -- Response time: 11  Turnaround: 12  Wait: 11
Job 1 -- Response time: 12  Turnaround: 112  Wait: 12
Job 0 -- Response time: 112  Turnaround: 1112  Wait: 112
Average -- Response: 13.57  Turnaround 93.00  Wait 13.57
End analyzing SJF.

Test Procedures:	bash run_tests.sh

Test Data:			.in files with a list of jobs with simulated length. Each job broken up with newline.

References:			CS3013 Lectures
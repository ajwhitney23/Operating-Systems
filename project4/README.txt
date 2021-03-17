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

Additional Files:		README.txt, ajwhitney.docx, nmbargman.docx, Makefile, problem1_explanation.txt, problem2_explanation.txt, project4.pdf

Additional Notes:       Problem 2 Takes a while to run to prevent deadlocks

Results:

      Sample:


Start of problem number 1

Dancers[15] = 15/33 | Jugglers[8] = 8/33 | Soloists[2] = 10/33
Juggler 1 entering the stage at position 1
Juggler 2 entering the stage at position 2
Juggler 3 entering the stage at position 3
Dancers[15] = 75/97 | Jugglers[4] = 4/97 | Soloists[2] = 18/97
Juggler 4 entering the stage at position 4
Juggler 4 now exiting the stage at position 4 after performing for 1 minutes
Juggler 1 now exiting the stage at position 1 after performing for 2 minutes
Juggler 3 now exiting the stage at position 3 after performing for 2 minutes
Juggler 2 now exiting the stage at position 2 after performing for 3 minutes
Dancer 1 entering the stage at position 1
Dancer 2 entering the stage at position 2
Dancer 3 entering the stage at position 3
Dancers[11] = 11/49 | Jugglers[4] = 20/49 | Soloists[2] = 18/49
Dancer 4 entering the stage at position 4
Dancer 3 now exiting the stage at position 3 after performing for 1 minutes
Dancer 2 now exiting the stage at position 2 after performing for 2 minutes
Dancer 1 now exiting the stage at position 1 after performing for 3 minutes
Dancer 4 now exiting the stage at position 4 after performing for 3 minutes
Juggler 5 entering the stage at position 1
Juggler 6 entering the stage at position 2
Juggler 7 entering the stage at position 3
Dancers[11] = 55/73 | Jugglers[0] = 0/73 | Soloists[2] = 18/73
Juggler 8 entering the stage at position 4
Juggler 5 now exiting the stage at position 1 after performing for 1 minutes
Juggler 7 now exiting the stage at position 3 after performing for 2 minutes
Juggler 8 now exiting the stage at position 4 after performing for 2 minutes
Juggler 6 now exiting the stage at position 2 after performing for 3 minutes
Dancer 5 entering the stage at position 1
Dancer 6 entering the stage at position 2
Dancer 7 entering the stage at position 3
Dancers[7] = 7/25 | Jugglers[0] = 0/25 | Soloists[2] = 18/25
Dancer 8 entering the stage at position 4
Dancer 6 now exiting the stage at position 2 after performing for 2 minutes
Dancer 7 now exiting the stage at position 3 after performing for 2 minutes
Dancer 8 now exiting the stage at position 4 after performing for 3 minutes
Dancer 5 now exiting the stage at position 1 after performing for 3 minutes
Dancers[7] = 14/19 | Jugglers[0] = 0/19 | Soloists[1] = 5/19
Soloist 1 entering the stage at position 1
Soloist 1 now exiting the stage at position 1 after performing for 2 minutes
Dancers[7] = 14/14 | Jugglers[0] = 0/14 | Soloists[0] = 0/14
Soloist 2 entering the stage at position 1
Soloist 2 now exiting the stage at position 1 after performing for 3 minutes
Dancer 9 entering the stage at position 1
Dancer 10 entering the stage at position 2
Dancer 11 entering the stage at position 3
Dancers[3] = 3/3 | Jugglers[0] = 0/3 | Soloists[0] = 0/3
Dancer 12 entering the stage at position 4
Dancer 9 now exiting the stage at position 1 after performing for 1 minutes
Dancers[2] = 2/2 | Jugglers[0] = 0/2 | Soloists[0] = 0/2
Dancer 13 entering the stage at position 1
Dancer 10 now exiting the stage at position 2 after performing for 3 minutes
Dancer 11 now exiting the stage at position 3 after performing for 3 minutes
Dancer 14 entering the stage at position 2
Dancers[0] = 0/0 | Jugglers[0] = 0/0 | Soloists[0] = 0/0
Dancer 15 entering the stage at position 3
Dancer 13 now exiting the stage at position 1 after performing for 2 minutes
Dancer 12 now exiting the stage at position 4 after performing for 3 minutes
Dancer 15 now exiting the stage at position 3 after performing for 1 minutes
Dancer 14 now exiting the stage at position 2 after performing for 1 minutes

Start of problem number 2

Packages: 1
Workers Active: B 1 | R 0 | G 0 | Y 0
Jose Drake [Blue][1] picked up Package [79] [shawl]
Stations Active: W 0 | B 1 | X 0 | J 0
Jose Drake [Blue][1] with Package [79] at [Barcoding] for 3 minute(s)
Packages: 2
Workers Active: B 1 | R 1 | G 0 | Y 0
Myrtle Cross [Red][11] picked up Package [78] [bottle cap]
Stations Active: W 0 | B 1 | X 0 | J 1
Myrtle Cross [Red][11] with Package [78] at [Jostiling] for 1 minute(s)
Packages: 3
Workers Active: B 1 | R 1 | G 1 | Y 0
Brett Wagner [Green][21] picked up Package [77] [floor]
Stations Active: W 0 | B 1 | X 1 | J 1
Brett Wagner [Green][21] with Package [77] at [Xraying] for 3 minute(s)
Packages: 4
Workers Active: B 1 | R 1 | G 1 | Y 1
Rita Pratt [Yellow][31] picked up Package [76] [twezzers]
Package [78][bottle cap] is now moving on the conveyor belt
Stations Active: W 0 | B 1 | X 1 | J 0
Stations Active: W 1 | B 1 | X 1 | J 0
Myrtle Cross [Red][11] with Package [78] at [Weighing] for 3 minute(s)
Package [79][shawl] is now moving on the conveyor belt
Stations Active: W 1 | B 0 | X 1 | J 0
Package [77][floor] is now moving on the conveyor belt
Stations Active: W 1 | B 1 | X 1 | J 0
Rita Pratt [Yellow][31] with Package [76] at [Barcoding] for 1 minute(s)
Stations Active: W 1 | B 1 | X 0 | J 0
Stations Active: W 1 | B 1 | X 0 | J 1
Brett Wagner [Green][21] with Package [77] at [Jostiling] for 1 minute(s)
Package [76][twezzers] is now moving on the conveyor belt
Package [77][floor] is now moving on the conveyor belt
Stations Active: W 1 | B 0 | X 0 | J 1
Stations Active: W 1 | B 0 | X 0 | J 0
Package [78][bottle cap] is now moving on the conveyor belt
Brett Wagner [Green][21] finished loading Package [77] [floor] on the delivery truck
Current number of packages: 3
Workers Active: B 1 | R 1 | G 0 | Y 1
Stations Active: W 1 | B 0 | X 0 | J 1
Rita Pratt [Yellow][31] with Package [76] at [Jostiling] for 2 minute(s) shaking the living hell out of it
Packages: 4
Workers Active: B 1 | R 1 | G 1 | Y 1
Barbara Yates [Green][22] picked up Package [75] [twister]
Stations Active: W 0 | B 0 | X 0 | J 1
Stations Active: W 0 | B 0 | X 1 | J 1
Myrtle Cross [Red][11] with Package [78] at [Xraying] for 1 minute(s)
Stations Active: W 1 | B 0 | X 1 | J 1
Jose Drake [Blue][1] with Package [79] at [Weighing] for 1 minute(s)
Package [78][bottle cap] is now moving on the conveyor belt
Stations Active: W 1 | B 0 | X 0 | J 1
Myrtle Cross [Red][11] finished loading Package [78] [bottle cap] on the delivery truck
Current number of packages: 3
Workers Active: B 1 | R 0 | G 1 | Y 1
Package [76][twezzers] is now moving on the conveyor belt
Packages: 4
Workers Active: B 1 | R 1 | G 1 | Y 1
Byron Newman [Red][12] picked up Package [74] [balloon]
Stations Active: W 1 | B 0 | X 0 | J 0
Package [79][shawl] is now moving on the conveyor belt
Stations Active: W 1 | B 0 | X 0 | J 1
Barbara Yates [Green][22] with Package [75] at [Jostiling] for 2 minute(s)
Stations Active: W 0 | B 0 | X 0 | J 1
Stations Active: W 1 | B 0 | X 0 | J 1
Byron Newman [Red][12] with Package [74] at [Weighing] for 1 minute(s)
Package [75][twister] is now moving on the conveyor belt
Stations Active: W 1 | B 0 | X 0 | J 0
Stations Active: W 1 | B 0 | X 1 | J 0
Barbara Yates [Green][22] with Package [75] at [Xraying] for 3 minute(s)
Stations Active: W 1 | B 0 | X 1 | J 1
Jose Drake [Blue][1] with Package [79] at [Jostiling] for 3 minute(s)
Package [74][balloon] is now moving on the conveyor belt

...

Final Results:

Team [Blue] processed [20] packages
Team [Red] processed [20] packages
Team [Green] processed [20] packages
Team [Yellow] processed [20] packages
Jose Drake delivered the most packages [2]
            

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

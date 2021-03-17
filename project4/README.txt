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

Additional Files:		output.txt, README.txt, ajwhitney.docx, nmbargman.docx, Makefile, problem1_explanation.txt, problem2_explanation.txt, project4.pdf

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

Jose Drake [Blue][1] picked up Package [79] [shawl]
Jose Drake [Blue][1] with Package [79] at [Barcoding] for 3 minute(s)
Myrtle Cross [Red][11] picked up Package [78] [bottle cap]
Myrtle Cross [Red][11] with Package [78] at [Jostiling] for 1 minute(s)
Brett Wagner [Green][21] picked up Package [77] [floor]
Brett Wagner [Green][21] with Package [77] at [Xraying] for 3 minute(s)
Rita Pratt [Yellow][31] picked up Package [76] [twezzers]
Myrtle Cross [Red][11] with Package [78] at [Weighing] for 3 minute(s)
Rita Pratt [Yellow][31] with Package [76] at [Barcoding] for 1 minute(s)
Brett Wagner [Green][21] with Package [77] at [Jostiling] for 1 minute(s)
Myrtle Cross [Red][11] with Package [78] at [Xraying] for 2 minute(s)
Brett Wagner [Green][21] finished loading Package [77] [floor] on the delivery truck
Jose Drake [Blue][1] with Package [79] at [Weighing] for 1 minute(s)
Rita Pratt [Yellow][31] with Package [76] at [Jostiling] for 1 minute(s) shaking the living hell out of it
Barbara Yates [Green][22] picked up Package [75] [twister]
Jose Drake [Blue][1] with Package [79] at [Jostiling] for 2 minute(s)
Rita Pratt [Yellow][31] with Package [76] at [Weighing] for 1 minute(s)
Myrtle Cross [Red][11] finished loading Package [78] [bottle cap] on the delivery truck
Byron Newman [Red][12] picked up Package [74] [balloon]
Rita Pratt [Yellow][31] finished loading Package [76] [twezzers] on the delivery truck
Byron Newman [Red][12] with Package [74] at [Weighing] for 3 minute(s)
Johnny Hale [Yellow][32] picked up Package [73] [cinder block]
Jose Drake [Blue][1] with Package [79] at [Xraying] for 3 minute(s)
Barbara Yates [Green][22] with Package [75] at [Jostiling] for 3 minute(s)
Johnny Hale [Yellow][32] with Package [73] at [Weighing] for 3 minute(s)
Jose Drake [Blue][1] finished loading Package [79] [shawl] on the delivery truck
Barbara Yates [Green][22] with Package [75] at [Xraying] for 3 minute(s)
Byron Newman [Red][12] with Package [74] at [Jostiling] for 3 minute(s) shaking the living hell out of it
Jordan Erickson [Blue][2] picked up Package [72] [apple]
Jordan Erickson [Blue][2] with Package [72] at [Barcoding] for 3 minute(s)
Jordan Erickson [Blue][2] with Package [72] at [Xraying] for 3 minute(s)
Byron Newman [Red][12] with Package [74] at [Barcoding] for 3 minute(s)
Barbara Yates [Green][22] with Package [75] at [Weighing] for 1 minute(s)
Byron Newman [Red][12] with Package [74] at [Xraying] for 1 minute(s)
Jordan Erickson [Blue][2] with Package [72] at [Weighing] for 1 minute(s)
Barbara Yates [Green][22] with Package [75] at [Barcoding] for 1 minute(s)
Jordan Erickson [Blue][2] finished loading Package [72] [apple] on the delivery truck
Byron Newman [Red][12] finished loading Package [74] [balloon] on the delivery truck
Johnny Hale [Yellow][32] with Package [73] at [Xraying] for 2 minute(s)
Don Stanley [Blue][3] picked up Package [71] [brocolli]
Don Stanley [Blue][3] with Package [71] at [Jostiling] for 3 minute(s)
Kelly Green [Red][13] picked up Package [70] [flag]
Barbara Yates [Green][22] finished loading Package [75] [twister] on the delivery truck
Gerald Baldwin [Green][23] picked up Package [69] [remote]
Johnny Hale [Yellow][32] with Package [73] at [Barcoding] for 1 minute(s)
Gerald Baldwin [Green][23] with Package [69] at [Xraying] for 3 minute(s)
Johnny Hale [Yellow][32] finished loading Package [73] [cinder block] on the delivery truck
Don Stanley [Blue][3] with Package [71] at [Weighing] for 2 minute(s)
Kelly Green [Red][13] with Package [70] at [Jostiling] for 3 minute(s)
Eric Lane [Yellow][33] picked up Package [68] [washing machine]
Eric Lane [Yellow][33] with Package [68] at [Barcoding] for 2 minute(s)
Eric Lane [Yellow][33] finished loading Package [68] [washing machine] on the delivery truck
Don Stanley [Blue][3] with Package [71] at [Xraying] for 1 minute(s)
Gerald Baldwin [Green][23] with Package [69] at [Weighing] for 3 minute(s)
Cecil Burton [Yellow][34] picked up Package [67] [soy sauce packet]
Cecil Burton [Yellow][34] with Package [67] at [Barcoding] for 1 minute(s)
Cecil Burton [Yellow][34] with Package [67] at [Jostiling] for 1 minute(s) shaking the living hell out of it
Don Stanley [Blue][3] finished loading Package [71] [brocolli] on the delivery truck
Kelly Green [Red][13] with Package [70] at [Xraying] for 2 minute(s)
Betty Perez [Blue][4] picked up Package [66] [bread]
Cecil Burton [Yellow][34] finished loading Package [67] [soy sauce packet] on the delivery truck
Vincent Mccoy [Yellow][35] picked up Package [65] [towel]
Gerald Baldwin [Green][23] finished loading Package [69] [remote] on the delivery truck
Betty Perez [Blue][4] with Package [66] at [Weighing] for 1 minute(s)
Betsy Silva [Green][24] picked up Package [64] [tire swing]
Betsy Silva [Green][24] with Package [64] at [Jostiling] for 3 minute(s)
Kelly Green [Red][13] with Package [70] at [Barcoding] for 3 minute(s)
Vincent Mccoy [Yellow][35] with Package [65] at [Xraying] for 2 minute(s)
Betty Perez [Blue][4] finished loading Package [66] [bread] on the delivery truck
Kelley Santos [Blue][5] picked up Package [63] [toothbrush]
Kelley Santos [Blue][5] with Package [63] at [Xraying] for 2 minute(s)
Kelly Green [Red][13] finished loading Package [70] [flag] on the delivery truck
Betsy Silva [Green][24] with Package [64] at [Weighing] for 1 minute(s)
Vincent Mccoy [Yellow][35] with Package [65] at [Jostiling] for 1 minute(s) shaking the living hell out of it
Danny Stewart [Red][14] picked up Package [62] [tooth picks]
Betsy Silva [Green][24] with Package [64] at [Xraying] for 3 minute(s)
Vincent Mccoy [Yellow][35] with Package [65] at [Barcoding] for 1 minute(s)
Danny Stewart [Red][14] with Package [62] at [Jostiling] for 1 minute(s) shaking the living hell out of it
Danny Stewart [Red][14] finished loading Package [62] [tooth picks] on the delivery truck
Vincent Mccoy [Yellow][35] with Package [65] at [Weighing] for 1 minute(s)

...

Final Results:

Team [Blue] processed [19] packages
Team [Red] processed [19] packages
Team [Green] processed [22] packages
Team [Yellow] processed [20] packages
Brett Wagner delivered the most packages [3]
            

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

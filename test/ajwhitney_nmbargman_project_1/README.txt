Author:				Andrew Whitney, Nathan Bargman
Date:				01/04/2021
Version:			V1.1
Project ID:			Project 1
CS Class:			CS3013
Programming Language:		C
OS/Hardware dependencies:	Ubuntu 16.04

Problem Description:		Exploring how processes work, how they share information, and how they are organzied.	

Program Assumptions 
      and Restrictions:		seed.txt, seed_x_x.txt files must be present

Implementation Details:
	Data			ints, timespec, char*, char**
	Variables		N/A 
	Algorithm		for loops and recursion

How to build the program:   make all to build all binaries
                            make clean to remove all binaries
                            make prolific to build prolific binary
                            make generation to build generation binary
                            make explorer to build explorer binary
                            make slugs to build slug and slugrace binary

Program Source:			prolific.c, generation.c, explorer.c, slug.c, slugrace.c

Additional Files:		seed.txt, seed_slug_1.txt, seed_slug_2.txt, seed_slug_3.txt, seed_slug_4.txt

Results:

Prolific Output:

Read seed value: 12345
Read seed value (converted to integer): 12345
Random Child Count: 13
I'm feeling prolific!
[Parent]: I am waiting for PID 1707 to finish.
        [Child, PID: 1707]: I am the child and I will wait 3 seconds and exit with code 22
        [Child, PID: 1707]: Now exiting...
[Parent]: Child 1707 exited with status code 22. Onward!
[Parent]: I am waiting for PID 1708 to finish.
        [Child, PID: 1708]: I am the child and I will wait 3 seconds and exit with code 24
        [Child, PID: 1708]: Now exiting...
[Parent]: Child 1708 exited with status code 24. Onward!
[Parent]: I am waiting for PID 1709 to finish.
        [Child, PID: 1709]: I am the child and I will wait 2 seconds and exit with code 2
        [Child, PID: 1709]: Now exiting...
[Parent]: Child 1709 exited with status code 2. Onward!
[Parent]: I am waiting for PID 1710 to finish.
        [Child, PID: 1710]: I am the child and I will wait 1 seconds and exit with code 22
        [Child, PID: 1710]: Now exiting...
[Parent]: Child 1710 exited with status code 22. Onward!
[Parent]: I am waiting for PID 1711 to finish.
        [Child, PID: 1711]: I am the child and I will wait 1 seconds and exit with code 5
        [Child, PID: 1711]: Now exiting...
[Parent]: Child 1711 exited with status code 5. Onward!
[Parent]: I am waiting for PID 1712 to finish.
        [Child, PID: 1712]: I am the child and I will wait 3 seconds and exit with code 38
        [Child, PID: 1712]: Now exiting...
[Parent]: Child 1712 exited with status code 38. Onward!
[Parent]: I am waiting for PID 1713 to finish.
        [Child, PID: 1713]: I am the child and I will wait 2 seconds and exit with code 3
        [Child, PID: 1713]: Now exiting...
[Parent]: Child 1713 exited with status code 3. Onward!
[Parent]: I am waiting for PID 1714 to finish.
        [Child, PID: 1714]: I am the child and I will wait 2 seconds and exit with code 29
        [Child, PID: 1714]: Now exiting...
[Parent]: Child 1714 exited with status code 29. Onward!
[Parent]: I am waiting for PID 1718 to finish.
        [Child, PID: 1718]: I am the child and I will wait 1 seconds and exit with code 29
        [Child, PID: 1718]: Now exiting...
[Parent]: Child 1718 exited with status code 29. Onward!
[Parent]: I am waiting for PID 1719 to finish.
        [Child, PID: 1719]: I am the child and I will wait 3 seconds and exit with code 28
        [Child, PID: 1719]: Now exiting...
[Parent]: Child 1719 exited with status code 28. Onward!
[Parent]: I am waiting for PID 1720 to finish.
        [Child, PID: 1720]: I am the child and I will wait 1 seconds and exit with code 48
        [Child, PID: 1720]: Now exiting...
[Parent]: Child 1720 exited with status code 48. Onward!
[Parent]: I am waiting for PID 1721 to finish.
        [Child, PID: 1721]: I am the child and I will wait 3 seconds and exit with code 22
        [Child, PID: 1721]: Now exiting...
[Parent]: Child 1721 exited with status code 22. Onward!
[Parent]: I am waiting for PID 1722 to finish.
        [Child, PID: 1722]: I am the child and I will wait 1 seconds and exit with code 4
        [Child, PID: 1722]: Now exiting...
[Parent]: Child 1722 exited with status code 4. Onward!


Generation Output:

Read seed value: 12345
Read seed value (converted to integer): 12345
Random Decendant Count: 10
Time to meet the kids/grandkids/great grandkids/...
[Parent, PID: 1747]: I am waiting for PID 1748 to finish.
        [Child, PID: 1748]: I was called with decendant count=10. I'll have 9 decendant(s).
[Parent, PID: 1748]: I am waiting for PID 1749 to finish.
        [Child, PID: 1749]: I was called with decendant count=9. I'll have 8 decendant(s).
[Parent, PID: 1749]: I am waiting for PID 1750 to finish.
        [Child, PID: 1750]: I was called with decendant count=8. I'll have 7 decendant(s).
[Parent, PID: 1750]: I am waiting for PID 1751 to finish.
        [Child, PID: 1751]: I was called with decendant count=7. I'll have 6 decendant(s).
[Parent, PID: 1751]: I am waiting for PID 1752 to finish.
        [Child, PID: 1752]: I was called with decendant count=6. I'll have 5 decendant(s).
[Parent, PID: 1752]: I am waiting for PID 1753 to finish.
        [Child, PID: 1753]: I was called with decendant count=5. I'll have 4 decendant(s).
[Parent, PID: 1753]: I am waiting for PID 1754 to finish.
        [Child, PID: 1754]: I was called with decendant count=4. I'll have 3 decendant(s).
[Parent, PID: 1754]: I am waiting for PID 1755 to finish.
        [Child, PID: 1755]: I was called with decendant count=3. I'll have 2 decendant(s).
[Parent, PID: 1755]: I am waiting for PID 1756 to finish.
        [Child, PID: 1756]: I was called with decendant count=2. I'll have 1 decendant(s).
[Parent, PID: 1756]: I am waiting for PID 1757 to finish.
        [Child, PID: 1757]: I was called with decendant count=1. I'll have 0 decendant(s).
[Parent, PID: 1756]: Child 1757 finished with status code 0. It's now my turn to exit.
[Parent, PID: 1755]: Child 1756 finished with status code 1. It's now my turn to exit.
[Parent, PID: 1754]: Child 1755 finished with status code 2. It's now my turn to exit.
[Parent, PID: 1753]: Child 1754 finished with status code 3. It's now my turn to exit.
[Parent, PID: 1752]: Child 1753 finished with status code 4. It's now my turn to exit.
[Parent, PID: 1751]: Child 1752 finished with status code 5. It's now my turn to exit.
[Parent, PID: 1750]: Child 1751 finished with status code 6. It's now my turn to exit.
[Parent, PID: 1749]: Child 1750 finished with status code 7. It's now my turn to exit.
[Parent, PID: 1748]: Child 1749 finished with status code 8. It's now my turn to exit.
[Parent, PID: 1747]: Child 1748 finished with status code 9. It's now my turn to exit.

Explorer Output:

Read seed value: 12345
Read seed value (converted to integer): 12345
It's time to see the world/file system!
Selection #1: /usr [SUCCESS]
Current reported directory: /usr
[Parent]: I am waiting for PID 1771 to finish.
        [Child, PID: 1771]: Executing 'ls -alh' command...
total 0
drwxr-xr-x 1 root root 4.0K Aug 22 04:09 .
drwxr-xr-x 1 root root 4.0K Jan 29 09:35 ..
drwxr-xr-x 1 root root 4.0K Feb  5 09:27 bin
drwxr-xr-x 1 root root 4.0K Apr 12  2016 games
drwxr-xr-x 1 root root 4.0K Jan 30 12:45 include
drwxr-xr-x 1 root root 4.0K Jan 29 11:35 lib
drwxr-xr-x 1 root root 4.0K Aug 22 04:09 local
drwxr-xr-x 1 root root 4.0K Jan 29 09:46 sbin
drwxr-xr-x 1 root root 4.0K Jan 30 13:22 share
drwxr-xr-x 1 root root 4.0K Aug 22 04:14 src
[Parent]: Child 1771 exited with status code 0. Onward!
Selection #2: /bin [SUCCESS]
Current reported directory: /bin
[Parent]: I am waiting for PID 1772 to finish.
        [Child, PID: 1772]: Executing 'ls -alh' command...
total 16M
drwxr-xr-x 1 root root  4.0K Jan 29 09:45 .
drwxr-xr-x 1 root root  4.0K Jan 29 09:35 ..
-rwxr-xr-x 1 root root 1014K Jul 12  2019 bash
-rwxr-xr-x 1 root root  509K Aug 13  2019 btrfs
-rwxr-xr-x 1 root root  244K Aug 13  2019 btrfs-calc-size
lrwxrwxrwx 1 root root     5 Aug 13  2019 btrfsck -> btrfs
-rwxr-xr-x 1 root root  272K Aug 13  2019 btrfs-convert
-rwxr-xr-x 1 root root  244K Aug 13  2019 btrfs-debug-tree
[truncated 165 lines]
[Parent]: Child 1772 exited with status code 0. Onward!
Selection #3: /bin [SUCCESS]
Current reported directory: /bin
[Parent]: I am waiting for PID 1773 to finish.
        [Child, PID: 1773]: Executing 'ls -alh' command...
total 16M
drwxr-xr-x 1 root root  4.0K Jan 29 09:45 .
drwxr-xr-x 1 root root  4.0K Jan 29 09:35 ..
-rwxr-xr-x 1 root root 1014K Jul 12  2019 bash
-rwxr-xr-x 1 root root  509K Aug 13  2019 btrfs
-rwxr-xr-x 1 root root  244K Aug 13  2019 btrfs-calc-size
lrwxrwxrwx 1 root root     5 Aug 13  2019 btrfsck -> btrfs
-rwxr-xr-x 1 root root  272K Aug 13  2019 btrfs-convert
-rwxr-xr-x 1 root root  244K Aug 13  2019 btrfs-debug-tree
-rwxr-xr-x 1 root root  240K Aug 13  2019 btrfs-find-root
-rwxr-xr-x 1 root root  264K Aug 13  2019 btrfs-image
-rwxr-xr-x 1 root root  244K Aug 13  2019 btrfs-map-logical
-rwxr-xr-x 1 root root  240K Aug 13  2019 btrfs-select-super
-rwxr-xr-x 1 root root  248K Aug 13  2019 btrfs-show-super
[truncated 180 lines]
[Parent]: Child 1773 exited with status code 0. Onward!
Selection #4: /proc [SUCCESS]
Current reported directory: /proc
[Parent]: I am waiting for PID 1774 to finish.
        [Child, PID: 1774]: Executing 'ls -alh' command...
total 0
dr-xr-xr-x 19 root     root        0 Feb  8 10:18 .
drwxr-xr-x  1 root     root     4.0K Jan 29 09:35 ..
dr-xr-xr-x  7 root     root        0 Feb  8 10:18 1
dr-xr-xr-x  7 root     root        0 Feb  8 10:18 158
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 159
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 161
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 162
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 167
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 169
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:28 1770
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:28 1774
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 190
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 201
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 219
dr-xr-xr-x  7 root     root        0 Feb  8 10:18 8
dr-xr-xr-x  7 awhitney awhitney    0 Feb  8 10:18 9
dr-xr-xr-x  2 root     root        0 Feb  8 10:18 bus
-r--r--r--  1 root     root        0 Feb  8 10:18 cgroups
-r--r--r--  1 root     root        0 Feb  8 10:18 cmdline
-r--r--r--  1 root     root        0 Feb  8 10:18 cpuinfo
-r--r--r--  1 root     root        0 Feb  8 10:18 filesystems
-r--r--r--  1 root     root        0 Feb  8 10:18 interrupts
-r--r--r--  1 root     root        0 Feb  8 10:18 loadavg
-r--r--r--  1 root     root        0 Feb  8 10:18 meminfo
lrwxrwxrwx  1 root     root        0 Feb  8 10:18 mounts -> self/mounts
lrwxrwxrwx  1 root     root        0 Feb  8 10:18 net -> self/net
lrwxrwxrwx  1 root     root        0 Feb  8 10:18 self -> 1774
-r--r--r--  1 root     root        0 Feb  8 10:18 stat
dr-xr-xr-x  6 root     root        0 Feb  8 10:18 sys
dr-xr-xr-x  2 root     root        0 Feb  8 10:18 tty
-r--r--r--  1 root     root        0 Feb  8 10:18 uptime
-r--r--r--  1 root     root        0 Feb  8 10:18 version
-r--r--r--  1 root     root        0 Feb  8 10:18 version_signature
[Parent]: Child 1774 exited with status code 0. Onward!
Selection #5: /usr [SUCCESS]
Current reported directory: /usr
[Parent]: I am waiting for PID 1775 to finish.
        [Child, PID: 1775]: Executing 'ls -alh' command...
total 0
drwxr-xr-x 1 root root 4.0K Aug 22 04:09 .
drwxr-xr-x 1 root root 4.0K Jan 29 09:35 ..
drwxr-xr-x 1 root root 4.0K Feb  5 09:27 bin
drwxr-xr-x 1 root root 4.0K Apr 12  2016 games
drwxr-xr-x 1 root root 4.0K Jan 30 12:45 include
drwxr-xr-x 1 root root 4.0K Jan 29 11:35 lib
drwxr-xr-x 1 root root 4.0K Aug 22 04:09 local
drwxr-xr-x 1 root root 4.0K Jan 29 09:46 sbin
drwxr-xr-x 1 root root 4.0K Jan 30 13:22 share
drwxr-xr-x 1 root root 4.0K Aug 22 04:14 src
[Parent]: Child 1775 exited with status code 0. Onward!

Slug Output:

awhitney@DESKTOP-AJW ~/p/project1> ./slug 1
[Slug PID: 1484]: Read seed value: 55555
[Slug PID: 1484]: Read seed value (converted to integer): 55555
[Slug PID: 1484]: Delay time is 3 seconds. Coin flip: 0
[Slug PID: 1484]: I'll get the job done. Eventually...
[Slug PID: 1484]: Break time is over! I am running the 'last -d --fulltimes' command.

wtmp begins Fri Jan 29 09:35:36 2021

Slugrace Output:

[Parent]: I forked off child 1451
[Child PID: 1451]: Executing './slug 1' command...
[Parent]: I forked off child 1452
[Child PID: 1452]: Executing './slug 2' command...
[Slug PID: 1451]: Read seed value: 55555
[Slug PID: 1451]: Read seed value (converted to integer): 55555
[Slug PID: 1451]: Delay time is 3 seconds. Coin flip: 0
[Slug PID: 1451]: I'll get the job done. Eventually...
[Parent]: I forked off child 1453
[Child PID: 1453]: Executing './slug 3' command...
[Slug PID: 1452]: Read seed value: 56789
[Slug PID: 1452]: Read seed value (converted to integer): 56789
[Slug PID: 1452]: Delay time is 2 seconds. Coin flip: 1
[Slug PID: 1452]: I'll get the job done. Eventually...
[Parent]: I forked off child 1454
[Child PID: 1454]: Executing './slug 4' command...
The race is still going. The following children are still racing: 1451 1452 1453 1454
[Slug PID: 1453]: Read seed value: 12345
[Slug PID: 1453]: Read seed value (converted to integer): 12345
[Slug PID: 1453]: Delay time is 4 seconds. Coin flip: 1
[Slug PID: 1453]: I'll get the job done. Eventually...
[Slug PID: 1454]: Read seed value: 456
[Slug PID: 1454]: Read seed value (converted to integer): 456
[Slug PID: 1454]: Delay time is 4 seconds. Coin flip: 1
[Slug PID: 1454]: I'll get the job done. Eventually...
The race is still going. The following children are still racing: 1451 1452 1453 1454
The race is still going. The following children are still racing: 1451 1452 1453 1454
The race is still going. The following children are still racing: 1451 1452 1453 1454
The race is still going. The following children are still racing: 1451 1452 1453 1454
The race is still going. The following children are still racing: 1451 1452 1453 1454
The race is still going. The following children are still racing: 1451 1452 1453 1454
The race is still going. The following children are still racing: 1451 1452 1453 1454
[Slug PID: 1452]: Break time is over! I am running the 'id -u' command.
The race is still going. The following children are still racing: 1451 1452 1453 1454
1000
The race is still going. The following children are still racing: 1451 1452 1453 1454
Child 1452 has crossed the finish line! It took 2.000000 seconds
The race is still going. The following children are still racing: 1451 1453 1454
The race is still going. The following children are still racing: 1451 1453 1454
[Slug PID: 1451]: Break time is over! I am running the 'last -d --fulltimes' command.

wtmp begins Fri Jan 29 09:35:36 2021
The race is still going. The following children are still racing: 1451 1453 1454
Child 1451 has crossed the finish line! It took 3.000000 seconds
The race is still going. The following children are still racing: 1453 1454
The race is still going. The following children are still racing: 1453 1454
The race is still going. The following children are still racing: 1453 1454
[Slug PID: 1453]: Break time is over! I am running the 'id -u' command.
[Slug PID: 1454]: Break time is over! I am running the 'id -u' command.
1000
The race is still going. The following children are still racing: 1453 1454
Child 1453 has crossed the finish line! It took 4.000000 seconds
1000
The race is still going. The following children are still racing: 1454
Child 1454 has crossed the finish line! It took 4.000000 seconds
The race is over! It took 4.000000 seconds

Test Procedures:		Program Output was compared to example output provided by assignment pdf.
                                Other seeds were tested to ensure the program executed differently with different seeds
Test Data:				seed.txt modified with other ints.
                                        seed_x_x.txt modified with other ints.

References:			CS3013 Lectures, Linux Man Pages (https://linux.die.net/man/)
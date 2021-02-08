Author:				Andrew Whitney, Nathan Bargman
Date:				01/04/2021
Version:			V1.0
Project ID:			Project 1
CS Class:			CS3013
Programming Language:		C
OS/Hardware dependencies:	how does the program rely on the operating system,
				   or on the hardware?

Problem Description:		a statement of the requirements

Overall Design:			main design decisions about the program
	System structure	
	Data representation	
	Algorithms 		

Program Assumptions 
      and Restrictions:		seed.txt, seed_x_x.txt files must be present

Interfaces:			how the program interacts with users, data or programs
	User
	File/D-B
	Program/Module

Implementation Details:
	Data			implementation details of data representation
	Variables		key variables and their scopes
	Algorithm		implementation details of algorithm(s) used

How to build the program:	make all to build all binaries
                            make clean to remove all binaries
                            make prolific to build prolific binary
                            make generation to build generation binary
                            make slugs to build slug and slugrace binary

Program Source:			prolific.c, generation.c, slug.c, slugrace.c

Additional Files:		seed.txt, seed_slug_1.txt, seed_slug_2.txt, seed_slug_3.txt, seed_slug_4.txt

Results:			listing of sample run(s) of the program

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
-rwxr-xr-x 1 root root  240K Aug 13  2019 btrfs-find-root
-rwxr-xr-x 1 root root  264K Aug 13  2019 btrfs-image
-rwxr-xr-x 1 root root  244K Aug 13  2019 btrfs-map-logical
-rwxr-xr-x 1 root root  240K Aug 13  2019 btrfs-select-super
-rwxr-xr-x 1 root root  248K Aug 13  2019 btrfs-show-super
-rwxr-xr-x 1 root root  244K Aug 13  2019 btrfstune
-rwxr-xr-x 1 root root  240K Aug 13  2019 btrfs-zero-log
-rwxr-xr-x 3 root root   31K Jul  4  2019 bunzip2
-rwxr-xr-x 1 root root  1.9M Mar  7  2019 busybox
-rwxr-xr-x 3 root root   31K Jul  4  2019 bzcat
lrwxrwxrwx 1 root root     6 Jul  4  2019 bzcmp -> bzdiff
-rwxr-xr-x 1 root root  2.1K Jul  4  2019 bzdiff
lrwxrwxrwx 1 root root     6 Jul  4  2019 bzegrep -> bzgrep
-rwxr-xr-x 1 root root  4.8K Jul  4  2019 bzexe
lrwxrwxrwx 1 root root     6 Jul  4  2019 bzfgrep -> bzgrep
-rwxr-xr-x 1 root root  3.6K Jul  4  2019 bzgrep
-rwxr-xr-x 3 root root   31K Jul  4  2019 bzip2
-rwxr-xr-x 1 root root   15K Jul  4  2019 bzip2recover
lrwxrwxrwx 1 root root     6 Jul  4  2019 bzless -> bzmore
-rwxr-xr-x 1 root root  1.3K Jul  4  2019 bzmore
-rwxr-xr-x 1 root root   51K Mar  2  2017 cat
-rwxr-xr-x 1 root root   15K Feb  7  2016 chacl
-rwxr-xr-x 1 root root   59K Mar  2  2017 chgrp
-rwxr-xr-x 1 root root   55K Mar  2  2017 chmod
-rwxr-xr-x 1 root root   63K Mar  2  2017 chown
-rwxr-xr-x 1 root root   11K Sep 22  2016 chvt
-rwxr-xr-x 1 root root  148K Mar  2  2017 cp
-rwxr-xr-x 1 root root  139K Nov  5  2019 cpio
-rwxr-xr-x 1 root root  151K Feb 17  2016 dash
-rwxr-xr-x 1 root root   67K Mar  2  2017 date
-rwxr-xr-x 1 root root   71K Mar  2  2017 dd
-rwxr-xr-x 1 root root   96K Mar  2  2017 df
-rwxr-xr-x 1 root root  124K Mar  2  2017 dir
-rwxr-xr-x 1 root root   60K Jan 27  2020 dmesg
lrwxrwxrwx 1 root root     8 Nov 24  2015 dnsdomainname -> hostname
lrwxrwxrwx 1 root root     8 Nov 24  2015 domainname -> hostname
-rwxr-xr-x 1 root root   81K Sep 22  2016 dumpkeys
-rwxr-xr-x 1 root root   31K Mar  2  2017 echo
-rwxr-xr-x 1 root root   51K Apr 26  2014 ed
-rwxr-xr-x 1 root root    28 Apr 29  2016 egrep
-rwxr-xr-x 1 root root   27K Mar  2  2017 false
-rwxr-xr-x 1 root root   11K Sep 22  2016 fgconsole
-rwxr-xr-x 1 root root    28 Apr 29  2016 fgrep
-rwxr-xr-x 1 root root   49K Jan 27  2020 findmnt
-rwxr-xr-x 1 root root  1.2K Aug 13  2019 fsck.btrfs
-rwxr-xr-x 1 root root   36K Aug 20  2019 fuser
-rwsr-xr-x 1 root root   31K Jul 12  2016 fusermount
-rwxr-xr-x 1 root root   24K Feb  7  2016 getfacl
-rwxr-xr-x 1 root root  207K Apr 29  2016 grep
-rwxr-xr-x 2 root root  2.3K Oct 27  2014 gunzip
-rwxr-xr-x 1 root root  5.8K Oct 27  2014 gzexe
-rwxr-xr-x 1 root root   96K Oct 27  2014 gzip
-rwxr-xr-x 1 root root   15K Nov 24  2015 hostname
-rwxr-xr-x 1 root root  368K Apr 16  2019 ip
-rwxr-xr-x 1 root root  488K Sep  4 05:31 journalctl
-rwxr-xr-x 1 root root   11K Sep 22  2016 kbd_mode
-rwxr-xr-x 1 root root   23K Mar  5  2020 kill
-rwxr-xr-x 1 root root  148K Nov 12  2018 kmod
-rwxr-xr-x 1 root root  167K Apr  5  2017 less
-rwxr-xr-x 1 root root   11K Apr  5  2017 lessecho
lrwxrwxrwx 1 root root     8 Apr  5  2017 lessfile -> lesspipe
-rwxr-xr-x 1 root root   20K Apr  5  2017 lesskey
-rwxr-xr-x 1 root root  7.6K Apr  5  2017 lesspipe
-rwxr-xr-x 1 root root   55K Mar  2  2017 ln
-rwxr-xr-x 1 root root  109K Sep 22  2016 loadkeys
-rwxr-xr-x 1 root root   47K Mar 26  2019 login
-rwxr-xr-x 1 root root  444K Sep  4 05:31 loginctl
-rwxr-xr-x 1 root root  103K Mar 21  2019 lowntfs-3g
-rwxr-xr-x 1 root root  124K Mar  2  2017 ls
-rwxr-xr-x 1 root root   76K Jan 27  2020 lsblk
lrwxrwxrwx 1 root root     4 Nov 12  2018 lsmod -> kmod
-rwxr-xr-x 1 root root   76K Mar  2  2017 mkdir
-rwxr-xr-x 1 root root  260K Aug 13  2019 mkfs.btrfs
-rwxr-xr-x 1 root root   63K Mar  2  2017 mknod
-rwxr-xr-x 1 root root   39K Mar  2  2017 mktemp
-rwxr-xr-x 1 root root   39K Jan 27  2020 more
-rwsr-xr-x 1 root root   40K Jan 27  2020 mount
-rwxr-xr-x 1 root root   15K Jan 27  2020 mountpoint
lrwxrwxrwx 1 root root    20 Aug 22 04:09 mt -> /etc/alternatives/mt
-rwxr-xr-x 1 root root   68K Nov  5  2019 mt-gnu
-rwxr-xr-x 1 root root  128K Mar  2  2017 mv
-rwxr-xr-x 1 root root  204K Feb 15  2017 nano
lrwxrwxrwx 1 root root    20 Aug 22 04:09 nc -> /etc/alternatives/nc
-rwxr-xr-x 1 root root   31K Dec  3  2012 nc.openbsd
lrwxrwxrwx 1 root root    24 Aug 22 04:09 netcat -> /etc/alternatives/netcat
-rwxr-xr-x 1 root root  117K Jun 30  2014 netstat
-rwxr-xr-x 1 root root  663K Sep  4 05:31 networkctl
lrwxrwxrwx 1 root root     8 Nov 24  2015 nisdomainname -> hostname
-rwxr-xr-x 1 root root  139K Mar 21  2019 ntfs-3g
-rwxr-xr-x 1 root root   11K Mar 21  2019 ntfs-3g.probe
-rwxr-xr-x 1 root root   67K Mar 21  2019 ntfs-3g.secaudit
-rwxr-xr-x 1 root root   18K Mar 21  2019 ntfs-3g.usermap
-rwxr-xr-x 1 root root   27K Mar 21  2019 ntfscat
-rwxr-xr-x 1 root root   31K Mar 21  2019 ntfscluster
-rwxr-xr-x 1 root root   35K Mar 21  2019 ntfscmp
-rwxr-xr-x 1 root root   35K Mar 21  2019 ntfsfallocate
-rwxr-xr-x 1 root root   39K Mar 21  2019 ntfsfix
-rwxr-xr-x 1 root root   55K Mar 21  2019 ntfsinfo
-rwxr-xr-x 1 root root   32K Mar 21  2019 ntfsls
-rwxr-xr-x 1 root root   31K Mar 21  2019 ntfsmove
-rwxr-xr-x 1 root root   39K Mar 21  2019 ntfstruncate
-rwxr-xr-x 1 root root   47K Mar 21  2019 ntfswipe
lrwxrwxrwx 1 root root     6 Sep 22  2016 open -> openvt
-rwxr-xr-x 1 root root   19K Sep 22  2016 openvt
lrwxrwxrwx 1 root root    14 Feb  5  2016 pidof -> /sbin/killall5
-rwsr-xr-x 1 root root   44K May  7  2014 ping
-rwsr-xr-x 1 root root   44K May  7  2014 ping6
-rwxr-xr-x 1 root root   39K May  9  2018 plymouth
-rwxr-xr-x 1 root root   96K Mar  5  2020 ps
-rwxr-xr-x 1 root root   31K Mar  2  2017 pwd
lrwxrwxrwx 1 root root     4 Jul 12  2019 rbash -> bash
-rwxr-xr-x 1 root root   39K Mar  2  2017 readlink
-rwxr-xr-x 1 root root    89 Apr 26  2014 red
-rwxr-xr-x 1 root root   59K Mar  2  2017 rm
-rwxr-xr-x 1 root root   39K Mar  2  2017 rmdir
lrwxrwxrwx 1 root root     4 Feb 15  2017 rnano -> nano
-rwxr-xr-x 1 root root   19K Jan 26  2016 run-parts
-rwxr-xr-x 1 root root   72K Feb 11  2016 sed
-rwxr-xr-x 1 root root   36K Feb  7  2016 setfacl
-rwxr-xr-x 1 root root   40K Sep 22  2016 setfont
-rwxr-xr-x 1 root root   30K Apr 10  2019 setupcon
lrwxrwxrwx 1 root root     4 Feb 17  2016 sh -> dash
lrwxrwxrwx 1 root root     4 Feb 17  2016 sh.distrib -> dash
-rwxr-xr-x 1 root root   31K Mar  2  2017 sleep
-rwxr-xr-x 1 root root  114K Apr 16  2019 ss
lrwxrwxrwx 1 root root     7 Mar  7  2019 static-sh -> busybox
-rwxr-xr-x 1 root root   71K Mar  2  2017 stty
-rwsr-xr-x 1 root root   40K Mar 26  2019 su
-rwxr-xr-x 1 root root   31K Mar  2  2017 sync
-rwxr-xr-x 1 root root  649K Sep  4 05:31 systemctl
lrwxrwxrwx 1 root root    20 Sep  4 05:31 systemd -> /lib/systemd/systemd
-rwxr-xr-x 1 root root   51K Sep  4 05:31 systemd-ask-password
-rwxr-xr-x 1 root root   39K Sep  4 05:31 systemd-escape
-rwxr-xr-x 1 root root   63K Sep  4 05:31 systemd-hwdb
-rwxr-xr-x 1 root root  276K Sep  4 05:31 systemd-inhibit
-rwxr-xr-x 1 root root   47K Sep  4 05:31 systemd-machine-id-setup
-rwxr-xr-x 1 root root   35K Sep  4 05:31 systemd-notify
-rwxr-xr-x 1 root root  143K Sep  4 05:31 systemd-tmpfiles
-rwxr-xr-x 1 root root   67K Sep  4 05:31 systemd-tty-ask-password-agent
-rwxr-xr-x 1 root root   23K Jan 27  2020 tailf
-rwxr-xr-x 1 root root  375K Jan 11 12:30 tar
-rwxr-xr-x 1 root root   11K Jan 26  2016 tempfile
-rwxr-xr-x 1 root root   63K Mar  2  2017 touch
-rwxr-xr-x 1 root root   27K Mar  2  2017 true
-rwxr-xr-x 1 root root  439K Sep  4 05:31 udevadm
-rwxr-xr-x 1 root root   14K Jul 12  2016 ulockmgr_server
-rwsr-xr-x 1 root root   27K Jan 27  2020 umount
-rwxr-xr-x 1 root root   31K Mar  2  2017 uname
-rwxr-xr-x 2 root root  2.3K Oct 27  2014 uncompress
-rwxr-xr-x 1 root root  2.7K Sep 22  2016 unicode_start
-rwxr-xr-x 1 root root  124K Mar  2  2017 vdir
-rwxr-xr-x 1 root root   31K Jan 27  2020 wdctl
-rwxr-xr-x 1 root root   946 Jan 26  2016 which
-rwxr-xr-x 1 root root   27K Jan 18  2016 whiptail
lrwxrwxrwx 1 root root     5 Jan 29 09:35 wslpath -> /init
lrwxrwxrwx 1 root root     8 Nov 24  2015 ypdomainname -> hostname
-rwxr-xr-x 1 root root  1.9K Oct 27  2014 zcat
-rwxr-xr-x 1 root root  1.8K Oct 27  2014 zcmp
-rwxr-xr-x 1 root root  5.7K Oct 27  2014 zdiff
-rwxr-xr-x 1 root root   140 Oct 27  2014 zegrep
-rwxr-xr-x 1 root root   140 Oct 27  2014 zfgrep
-rwxr-xr-x 1 root root  2.1K Oct 27  2014 zforce
-rwxr-xr-x 1 root root  5.8K Oct 27  2014 zgrep
-rwxr-xr-x 1 root root  2.0K Oct 27  2014 zless
-rwxr-xr-x 1 root root  1.9K Oct 27  2014 zmore
-rwxr-xr-x 1 root root  5.0K Oct 27  2014 znew
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
-rwxr-xr-x 1 root root  244K Aug 13  2019 btrfstune
-rwxr-xr-x 1 root root  240K Aug 13  2019 btrfs-zero-log
-rwxr-xr-x 3 root root   31K Jul  4  2019 bunzip2
-rwxr-xr-x 1 root root  1.9M Mar  7  2019 busybox
-rwxr-xr-x 3 root root   31K Jul  4  2019 bzcat
lrwxrwxrwx 1 root root     6 Jul  4  2019 bzcmp -> bzdiff
-rwxr-xr-x 1 root root  2.1K Jul  4  2019 bzdiff
lrwxrwxrwx 1 root root     6 Jul  4  2019 bzegrep -> bzgrep
-rwxr-xr-x 1 root root  4.8K Jul  4  2019 bzexe
lrwxrwxrwx 1 root root     6 Jul  4  2019 bzfgrep -> bzgrep
-rwxr-xr-x 1 root root  3.6K Jul  4  2019 bzgrep
-rwxr-xr-x 3 root root   31K Jul  4  2019 bzip2
-rwxr-xr-x 1 root root   15K Jul  4  2019 bzip2recover
lrwxrwxrwx 1 root root     6 Jul  4  2019 bzless -> bzmore
-rwxr-xr-x 1 root root  1.3K Jul  4  2019 bzmore
-rwxr-xr-x 1 root root   51K Mar  2  2017 cat
-rwxr-xr-x 1 root root   15K Feb  7  2016 chacl
-rwxr-xr-x 1 root root   59K Mar  2  2017 chgrp
-rwxr-xr-x 1 root root   55K Mar  2  2017 chmod
-rwxr-xr-x 1 root root   63K Mar  2  2017 chown
-rwxr-xr-x 1 root root   11K Sep 22  2016 chvt
-rwxr-xr-x 1 root root  148K Mar  2  2017 cp
-rwxr-xr-x 1 root root  139K Nov  5  2019 cpio
-rwxr-xr-x 1 root root  151K Feb 17  2016 dash
-rwxr-xr-x 1 root root   67K Mar  2  2017 date
-rwxr-xr-x 1 root root   71K Mar  2  2017 dd
-rwxr-xr-x 1 root root   96K Mar  2  2017 df
-rwxr-xr-x 1 root root  124K Mar  2  2017 dir
-rwxr-xr-x 1 root root   60K Jan 27  2020 dmesg
lrwxrwxrwx 1 root root     8 Nov 24  2015 dnsdomainname -> hostname
lrwxrwxrwx 1 root root     8 Nov 24  2015 domainname -> hostname
-rwxr-xr-x 1 root root   81K Sep 22  2016 dumpkeys
-rwxr-xr-x 1 root root   31K Mar  2  2017 echo
-rwxr-xr-x 1 root root   51K Apr 26  2014 ed
-rwxr-xr-x 1 root root    28 Apr 29  2016 egrep
-rwxr-xr-x 1 root root   27K Mar  2  2017 false
-rwxr-xr-x 1 root root   11K Sep 22  2016 fgconsole
-rwxr-xr-x 1 root root    28 Apr 29  2016 fgrep
-rwxr-xr-x 1 root root   49K Jan 27  2020 findmnt
-rwxr-xr-x 1 root root  1.2K Aug 13  2019 fsck.btrfs
-rwxr-xr-x 1 root root   36K Aug 20  2019 fuser
-rwsr-xr-x 1 root root   31K Jul 12  2016 fusermount
-rwxr-xr-x 1 root root   24K Feb  7  2016 getfacl
-rwxr-xr-x 1 root root  207K Apr 29  2016 grep
-rwxr-xr-x 2 root root  2.3K Oct 27  2014 gunzip
-rwxr-xr-x 1 root root  5.8K Oct 27  2014 gzexe
-rwxr-xr-x 1 root root   96K Oct 27  2014 gzip
-rwxr-xr-x 1 root root   15K Nov 24  2015 hostname
-rwxr-xr-x 1 root root  368K Apr 16  2019 ip
-rwxr-xr-x 1 root root  488K Sep  4 05:31 journalctl
-rwxr-xr-x 1 root root   11K Sep 22  2016 kbd_mode
-rwxr-xr-x 1 root root   23K Mar  5  2020 kill
-rwxr-xr-x 1 root root  148K Nov 12  2018 kmod
-rwxr-xr-x 1 root root  167K Apr  5  2017 less
-rwxr-xr-x 1 root root   11K Apr  5  2017 lessecho
lrwxrwxrwx 1 root root     8 Apr  5  2017 lessfile -> lesspipe
-rwxr-xr-x 1 root root   20K Apr  5  2017 lesskey
-rwxr-xr-x 1 root root  7.6K Apr  5  2017 lesspipe
-rwxr-xr-x 1 root root   55K Mar  2  2017 ln
-rwxr-xr-x 1 root root  109K Sep 22  2016 loadkeys
-rwxr-xr-x 1 root root   47K Mar 26  2019 login
-rwxr-xr-x 1 root root  444K Sep  4 05:31 loginctl
-rwxr-xr-x 1 root root  103K Mar 21  2019 lowntfs-3g
-rwxr-xr-x 1 root root  124K Mar  2  2017 ls
-rwxr-xr-x 1 root root   76K Jan 27  2020 lsblk
lrwxrwxrwx 1 root root     4 Nov 12  2018 lsmod -> kmod
-rwxr-xr-x 1 root root   76K Mar  2  2017 mkdir
-rwxr-xr-x 1 root root  260K Aug 13  2019 mkfs.btrfs
-rwxr-xr-x 1 root root   63K Mar  2  2017 mknod
-rwxr-xr-x 1 root root   39K Mar  2  2017 mktemp
-rwxr-xr-x 1 root root   39K Jan 27  2020 more
-rwsr-xr-x 1 root root   40K Jan 27  2020 mount
-rwxr-xr-x 1 root root   15K Jan 27  2020 mountpoint
lrwxrwxrwx 1 root root    20 Aug 22 04:09 mt -> /etc/alternatives/mt
-rwxr-xr-x 1 root root   68K Nov  5  2019 mt-gnu
-rwxr-xr-x 1 root root  128K Mar  2  2017 mv
-rwxr-xr-x 1 root root  204K Feb 15  2017 nano
lrwxrwxrwx 1 root root    20 Aug 22 04:09 nc -> /etc/alternatives/nc
-rwxr-xr-x 1 root root   31K Dec  3  2012 nc.openbsd
lrwxrwxrwx 1 root root    24 Aug 22 04:09 netcat -> /etc/alternatives/netcat
-rwxr-xr-x 1 root root  117K Jun 30  2014 netstat
-rwxr-xr-x 1 root root  663K Sep  4 05:31 networkctl
lrwxrwxrwx 1 root root     8 Nov 24  2015 nisdomainname -> hostname
-rwxr-xr-x 1 root root  139K Mar 21  2019 ntfs-3g
-rwxr-xr-x 1 root root   11K Mar 21  2019 ntfs-3g.probe
-rwxr-xr-x 1 root root   67K Mar 21  2019 ntfs-3g.secaudit
-rwxr-xr-x 1 root root   18K Mar 21  2019 ntfs-3g.usermap
-rwxr-xr-x 1 root root   27K Mar 21  2019 ntfscat
-rwxr-xr-x 1 root root   31K Mar 21  2019 ntfscluster
-rwxr-xr-x 1 root root   35K Mar 21  2019 ntfscmp
-rwxr-xr-x 1 root root   35K Mar 21  2019 ntfsfallocate
-rwxr-xr-x 1 root root   39K Mar 21  2019 ntfsfix
-rwxr-xr-x 1 root root   55K Mar 21  2019 ntfsinfo
-rwxr-xr-x 1 root root   32K Mar 21  2019 ntfsls
-rwxr-xr-x 1 root root   31K Mar 21  2019 ntfsmove
-rwxr-xr-x 1 root root   39K Mar 21  2019 ntfstruncate
-rwxr-xr-x 1 root root   47K Mar 21  2019 ntfswipe
lrwxrwxrwx 1 root root     6 Sep 22  2016 open -> openvt
-rwxr-xr-x 1 root root   19K Sep 22  2016 openvt
lrwxrwxrwx 1 root root    14 Feb  5  2016 pidof -> /sbin/killall5
-rwsr-xr-x 1 root root   44K May  7  2014 ping
-rwsr-xr-x 1 root root   44K May  7  2014 ping6
-rwxr-xr-x 1 root root   39K May  9  2018 plymouth
-rwxr-xr-x 1 root root   96K Mar  5  2020 ps
-rwxr-xr-x 1 root root   31K Mar  2  2017 pwd
lrwxrwxrwx 1 root root     4 Jul 12  2019 rbash -> bash
-rwxr-xr-x 1 root root   39K Mar  2  2017 readlink
-rwxr-xr-x 1 root root    89 Apr 26  2014 red
-rwxr-xr-x 1 root root   59K Mar  2  2017 rm
-rwxr-xr-x 1 root root   39K Mar  2  2017 rmdir
lrwxrwxrwx 1 root root     4 Feb 15  2017 rnano -> nano
-rwxr-xr-x 1 root root   19K Jan 26  2016 run-parts
-rwxr-xr-x 1 root root   72K Feb 11  2016 sed
-rwxr-xr-x 1 root root   36K Feb  7  2016 setfacl
-rwxr-xr-x 1 root root   40K Sep 22  2016 setfont
-rwxr-xr-x 1 root root   30K Apr 10  2019 setupcon
lrwxrwxrwx 1 root root     4 Feb 17  2016 sh -> dash
lrwxrwxrwx 1 root root     4 Feb 17  2016 sh.distrib -> dash
-rwxr-xr-x 1 root root   31K Mar  2  2017 sleep
-rwxr-xr-x 1 root root  114K Apr 16  2019 ss
lrwxrwxrwx 1 root root     7 Mar  7  2019 static-sh -> busybox
-rwxr-xr-x 1 root root   71K Mar  2  2017 stty
-rwsr-xr-x 1 root root   40K Mar 26  2019 su
-rwxr-xr-x 1 root root   31K Mar  2  2017 sync
-rwxr-xr-x 1 root root  649K Sep  4 05:31 systemctl
lrwxrwxrwx 1 root root    20 Sep  4 05:31 systemd -> /lib/systemd/systemd
-rwxr-xr-x 1 root root   51K Sep  4 05:31 systemd-ask-password
-rwxr-xr-x 1 root root   39K Sep  4 05:31 systemd-escape
-rwxr-xr-x 1 root root   63K Sep  4 05:31 systemd-hwdb
-rwxr-xr-x 1 root root  276K Sep  4 05:31 systemd-inhibit
-rwxr-xr-x 1 root root   47K Sep  4 05:31 systemd-machine-id-setup
-rwxr-xr-x 1 root root   35K Sep  4 05:31 systemd-notify
-rwxr-xr-x 1 root root  143K Sep  4 05:31 systemd-tmpfiles
-rwxr-xr-x 1 root root   67K Sep  4 05:31 systemd-tty-ask-password-agent
-rwxr-xr-x 1 root root   23K Jan 27  2020 tailf
-rwxr-xr-x 1 root root  375K Jan 11 12:30 tar
-rwxr-xr-x 1 root root   11K Jan 26  2016 tempfile
-rwxr-xr-x 1 root root   63K Mar  2  2017 touch
-rwxr-xr-x 1 root root   27K Mar  2  2017 true
-rwxr-xr-x 1 root root  439K Sep  4 05:31 udevadm
-rwxr-xr-x 1 root root   14K Jul 12  2016 ulockmgr_server
-rwsr-xr-x 1 root root   27K Jan 27  2020 umount
-rwxr-xr-x 1 root root   31K Mar  2  2017 uname
-rwxr-xr-x 2 root root  2.3K Oct 27  2014 uncompress
-rwxr-xr-x 1 root root  2.7K Sep 22  2016 unicode_start
-rwxr-xr-x 1 root root  124K Mar  2  2017 vdir
-rwxr-xr-x 1 root root   31K Jan 27  2020 wdctl
-rwxr-xr-x 1 root root   946 Jan 26  2016 which
-rwxr-xr-x 1 root root   27K Jan 18  2016 whiptail
lrwxrwxrwx 1 root root     5 Jan 29 09:35 wslpath -> /init
lrwxrwxrwx 1 root root     8 Nov 24  2015 ypdomainname -> hostname
-rwxr-xr-x 1 root root  1.9K Oct 27  2014 zcat
-rwxr-xr-x 1 root root  1.8K Oct 27  2014 zcmp
-rwxr-xr-x 1 root root  5.7K Oct 27  2014 zdiff
-rwxr-xr-x 1 root root   140 Oct 27  2014 zegrep
-rwxr-xr-x 1 root root   140 Oct 27  2014 zfgrep
-rwxr-xr-x 1 root root  2.1K Oct 27  2014 zforce
-rwxr-xr-x 1 root root  5.8K Oct 27  2014 zgrep
-rwxr-xr-x 1 root root  2.0K Oct 27  2014 zless
-rwxr-xr-x 1 root root  1.9K Oct 27  2014 zmore
-rwxr-xr-x 1 root root  5.0K Oct 27  2014 znew
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
Read seed value: 55555
Delay time is 3 seconds. Coin flip: 0
I'll get the job done. Eventually...
Break time is over! I am running the 'last -d --fulltimes' command.

wtmp begins Fri Jan 29 09:35:36 2021

Slugrace Output:

[Parent]: I forked off child 1845
[Child PID: 1845]: Executing './slug 1' command...
[Parent]: I forked off child 1846
[Child PID: 1846]: Executing './slug 2' command...
Read seed value: 55555
Delay time is 3 seconds. Coin flip: 0
I'll get the job done. Eventually...
[Parent]: I forked off child 1847
[Child PID: 1847]: Executing './slug 3' command...
Read seed value: 56789
Delay time is 2 seconds. Coin flip: 1
I'll get the job done. Eventually...
[Parent]: I forked off child 1848
[Child PID: 1848]: Executing './slug 4' command...
The race is still going. The following children are still racing: 1845 1846 1847 1848
Read seed value: 12345
Delay time is 4 seconds. Coin flip: 1
I'll get the job done. Eventually...
Read seed value: 456
Delay time is 4 seconds. Coin flip: 1
I'll get the job done. Eventually...
The race is still going. The following children are still racing: 1845 1846 1847 1848
The race is still going. The following children are still racing: 1845 1846 1847 1848
The race is still going. The following children are still racing: 1845 1846 1847 1848
The race is still going. The following children are still racing: 1845 1846 1847 1848
The race is still going. The following children are still racing: 1845 1846 1847 1848
The race is still going. The following children are still racing: 1845 1846 1847 1848
The race is still going. The following children are still racing: 1845 1846 1847 1848
Break time is over! I am running the 'id -u' command.
The race is still going. The following children are still racing: 1845 1846 1847 1848
1000
The race is still going. The following children are still racing: 1845 1846 1847 1848
Child 1846 has crossed the finish line! It took 2.000000 seconds
The race is still going. The following children are still racing: 1845 1847 1848
The race is still going. The following children are still racing: 1845 1847 1848
Break time is over! I am running the 'last -d --fulltimes' command.

wtmp begins Fri Jan 29 09:35:36 2021
The race is still going. The following children are still racing: 1845 1847 1848
Child 1845 has crossed the finish line! It took 3.000000 seconds
The race is still going. The following children are still racing: 1847 1848
The race is still going. The following children are still racing: 1847 1848
The race is still going. The following children are still racing: 1847 1848
Break time is over! I am running the 'id -u' command.
Break time is over! I am running the 'id -u' command.
The race is still going. The following children are still racing: 1847 1848
1000
1000
The race is still going. The following children are still racing: 1847 1848
Child 1847 has crossed the finish line! It took 4.000000 seconds
Child 1848 has crossed the finish line! It took 4.000000 seconds
The race is over! It took 4.000000 seconds

Test Procedures:		how the program was tested
Test Data:				test cases

Performance Evaluation:		how well the program performs
	Time/Space
	User Interface

References:			books, papers, people, web, ...
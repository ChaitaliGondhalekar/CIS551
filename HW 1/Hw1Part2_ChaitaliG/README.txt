Submitted by Chaitali Gondhalekar

How I attacked the system?

To make the program print “Ownz_U!”, which is not already available in program, unlike part1, first I need to put “Ownz_U!” somewhere on the stack where it can be accessed by program when attacked. First I copied the badbuf.c into a new file called mod_badbuf.c and printed the address of pw (s2) into a file. I printed in match function so that the address of pw wouldn’t be different than that in badbuf. 
I wrote the address obtained at good and evil, so that whatever be the return value of match, the same chunk of memory beginning at the “pw” will be accessed. Then I gave “Ownz_U!” as a part of pw to badbuf program and after some experimentation, I got the right input for badbuf.

Files and their functionalities

There are 9 files in all.
makefile - compiles and executes all the files in desired sequence.
mod_badbuf.c - prints the address of pw into a file named ipForIp, it prints its output in opOfMod and takes input from ipToMod
inputHw1.c - takes ipForIp as input, writes the input for badbuf in “file”
badbuf.c - the original program which takes “file” as input to generate desired output
logHw1Part2 - contains the log recorded using the script command

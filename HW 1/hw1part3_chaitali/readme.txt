CIS551 Homework 1 part 3
Submitted by Chaitali Gondhalekar

Logic:
Extending on the lines of Part2, the stack address of TOS or pw was obtained from modified badbuf program.
The requirement was to spawn a shell. This was to be done by just writing to the stack. I wrote shellcode.c, which would spawn the shell, further converted the c code into assembly, using inline function in exitchell.c. I then used objdump to obtain the hexcode corresponding to the assembly code, hardcoded the same into inputHw1.c. inputHw1.c generates the input file for badbuf.c that contains all the carefully adjusted characters to exploit the buffer overflow vulnerability. 

Files
1. makefile
2. inputHw1.c
3. badbuf.c
4. mod_badbuf.c
5. shellcode.c
6. exitshell.c
7. logPart3.txt

Instructions:
In the terminal, type
	$ make attack
press enter a couple of times, the shell is open. Try out commands like ls, whoami to test the shell.

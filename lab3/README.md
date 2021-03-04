### Question 3

For the assembly language discussed in Assignment 2, write a program that reads a file containing an assembly language program, 
and for each statement in the assembly program it prints the numeric opcode on the terminal in readable format, and in an output 
file in binary format.


### Running flex

write an assembly program and save it to a file(say filename.asm).

To run lspecs.l

```
flex lsepcs.l
gcc lex.yy.c -lfl
./a.out filename.asm
```

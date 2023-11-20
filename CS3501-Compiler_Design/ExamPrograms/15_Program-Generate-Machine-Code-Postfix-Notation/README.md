# Ex.No.15 - Develop a program to generate machine code from a given postfix notation,
```
$ cc gen.c -o gen.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./gen.out` in terminal.

OUTPUT:


`./gen.out`
```
Enter the postfix expression: ABC*+
MOV B,R0
MUL C,R1
MOV A,R1
ADD R,R2
Machine code generation completed.
```
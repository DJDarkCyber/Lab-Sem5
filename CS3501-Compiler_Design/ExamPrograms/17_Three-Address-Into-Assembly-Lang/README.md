# Ex.No.17 - Develop a program in C that converts the given three address code into assembly language statements.
```
$ cc gen.c -o gen.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./gen.out` in terminal.

OUTPUT:


`./gen.out`
```
Enter the number of three-address code instructions: 3
Enter three-address code:
Instruction 1: t1 = a + b
Instruction 2: t2 = c + d
Instruction 3: t3 = t1 + t2

Assembly code:
; Assembly code for three-address code 1
MOV , 1
ADD , 1, 1

; Assembly code for three-address code 2
MOV , 2
ADD , 2, 2

; Assembly code for three-address code 3
MOV 1, 3
ADD 2, 3, 3
```
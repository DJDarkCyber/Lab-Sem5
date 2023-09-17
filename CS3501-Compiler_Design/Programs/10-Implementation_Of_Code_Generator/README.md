# Ex.No.10 - Implementation of code generator.
```
$ cc code_gen.c -o code_gen.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./code_gen.out` in terminal.

OUTPUT:


`./code_gen.out`
```
Enter the number of intermediate codes: 4
Enter the three address code 1: A=B+C

Enter the three address code 2: D=E-F

Enter the three address code 3: G=H*I

Enter the three address code 4: J=K/L


The Generated code:

MOV +,R0
MOV R0,=

MOV -,R1
MOV R1,=

MOV *,R2
MOV R2,=

MOV /,R3
MOV R3,=

```
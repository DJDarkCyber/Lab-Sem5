# Ex.No.6 - Generate three address code for a simple program using LEX and YACC.

```
$ cc gen.c -o gen.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./gen.out` in terminal.

OUTPUT:


`./gen.out`
```
 1. Assignment
 2. Arithmetic
 3. Exit
 ENTER THE CHOICE:1

 Enter the expression with assignment operator:a=b
3 address code:
 temp=b 
 a=temp

 1. Assignment
 2. Arithmetic
 3. Exit
 ENTER THE CHOICE:2

 Enter the expression with arithmetic operator:a+5
3 address code:
 temp=a+5
 temp1=temp

 1. Assignment
 2. Arithmetic
 3. Exit
 ENTER THE CHOICE:3
```
# Ex.No.4.a - Design a program to recognize a valid variable which starts with an alphabet followed by any number of digits or alphabets using YACC tool

```
$ bison variableyacc.y
$ cc variableyacc.tab.c -o variableyacc.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./variableyacc.out` in terminal.

OUTPUT:


`./variableyacc.out`
```
Enter a variable: var12

Accepted
```

```
Enter a variable: 13Var
syntax error
Rejected
```
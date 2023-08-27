# Ex.No.4.a - YACC program to recognize a valid arithmetic expression that uses operators +,-,* and /

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
# Ex.No.18 - Develop a C program to eliminate left recursion from a grammar

```
$ cc el.c -o el.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./el.out` in terminal.

OUTPUT:


`./el.out`
```
Enter the number of rules: 1
Enter the non-terminals:
S
Enter the productions:
S -> S a | S b | c ;

Grammar after eliminating left recursion:
S -> a|Sb|cT'
T' -> a|Sb|cT' | ε
```
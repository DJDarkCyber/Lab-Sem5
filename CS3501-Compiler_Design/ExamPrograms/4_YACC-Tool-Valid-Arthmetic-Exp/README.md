# Ex.No.4 - Use YACC tool to recognize a valid arithmetic expression that uses basic arithmetic operators[+, -, *, /].
```
$ bison exp.y
$ cc exp.tab.c -o exp.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./exp.out` in terminal.

OUTPUT:


`./exp.out`
```
 Enter an expression to validate: c+a*5/b

 Valid 

```
# Ex.No.6 - Use LEX and YACC tools to implement a native calculator

```
$ lex calculator.l
$ yacc -d calculator.y
$ gcc lex.yy.c y.tab.c -o calculator.out -ll
```

Execution :

1. Navigate to your compiled program directory.
2. Run `././calculator.out` in terminal.

OUTPUT:


`./calculator.out`
```
1+2
Result: 3
1*3
Result: 3
2*3
Result: 6
3+12+43
Result: 58
```
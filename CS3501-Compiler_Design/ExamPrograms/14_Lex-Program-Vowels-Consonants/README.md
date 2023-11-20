# Ex.No.14 - Develop a Lex Program to find out the total number of vowels and consonants from the given input string.

```
$ flex lex1.l
$ cc lex.yy.c -o lex.out -ll
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./lex.out` in terminal.

OUTPUT:


`./lex.out Hello_World`
```
Total number of vowels: 3
Total number of consonants: 7
```
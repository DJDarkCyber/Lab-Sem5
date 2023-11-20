# Ex.No.16 - Write a LEX program to scan reserved words, variables and operators of C language

```
$ flex lex1.l
$ cc lex.yy.c -o lex.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./lex.out test.c` in terminal.

OUTPUT:


`./lex.out test.c`
```
#include<stdio.h> is a PREPROCESSOR DIRECTIVE


        int is a RESERVED WORD
 Variable: main
() {

        int is a RESERVED WORD
 Variable: a
, Variable: b
;
        Variable: a
 
        = is an ASSIGNMENT OPERATOR 10;
        Variable: b
 
        = is an ASSIGNMENT OPERATOR 12;
        Variable: a
 
        = is an ASSIGNMENT OPERATOR Variable: b
+Variable: c
;
}
```
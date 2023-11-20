# Ex.No.3 - Design a program that implements a lexical analyzer that separates tokens using a LEX tool

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


FUNCTION
        main(
        )


 BLOCK BEGINS

        int is a KEYWORD
 
        a IDENTIFIER,
        b IDENTIFIER;

 BLOCK ENDS
```
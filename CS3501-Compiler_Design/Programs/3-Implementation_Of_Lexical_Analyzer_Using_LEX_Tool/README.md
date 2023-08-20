# Ex.No.3 - Developing a lexical analyzer using LEX tool

```
$ flex lex1.l
$ cc cc lex.yy.c -o lex.out
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
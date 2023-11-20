# Ex.No.12 - Design a lexical analyzer that identifies comments, operators and keywords from a given expression

```
$ flex lex1.l
$ cc lex.yy.c -o lex.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./lex.out test.c` in terminal.

OUTPUT:


`./lex.out`
```
        main IDENTIFIER(
        )

{

        int is a KEYWORD
 
        a IDENTIFIER,
        b IDENTIFIER;

        a IDENTIFIER 
        = is an ASSIGNMENT OPERATOR 
        b IDENTIFIER;
}
```
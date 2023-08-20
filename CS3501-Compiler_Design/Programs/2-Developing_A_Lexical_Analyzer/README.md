# Ex.No.2 - Developing a lexical analyzer

```
$ cc lexical_analyzer.c -o lexical_analyzer.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./lexical_analyzer.out` in terminal.

OUTPUT:

`./lexical_analyzer.out`

```
Enter the expression: int a = 1; while(a==1){a++}

Keyword          Identifier      Constant        Operator        sp. Character 

int
                        a
                                                =
                                        1
                                                                ;
while
                                                                (
                        a
                                                =
                                                =
                                        1
                                                                )
                                                                {
                        a
                                                +
                                                +
                                                                }   
```
# Ex.No.1 - Developing a lexical analyzer

```
$ cc laxical_analyzer.c -o laxical_analyzer.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./laxical_analyzer.out` in terminal.

OUTPUT:

`./laxical_analyzer.out`

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
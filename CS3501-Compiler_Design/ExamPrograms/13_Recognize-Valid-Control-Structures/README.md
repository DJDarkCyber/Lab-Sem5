# Ex.No.13 - Develop a program to recognize a valid control structues syntax of C language (For loop, while loop, if else, if-else-if, switch-case, etc.).

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
int main(
        )
 {
        int i;

        for is a CONTROL STATEMENT
(i=0; i<10; i++
        )
{
                printf("%d", i
        );

        }
}
```
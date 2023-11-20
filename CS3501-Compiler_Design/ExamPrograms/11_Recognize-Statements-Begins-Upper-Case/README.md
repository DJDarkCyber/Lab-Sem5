# Ex.No.11 - Generate a valid pattern that recognizes all statements that begins with an Upper-Case Letter followed by five digits or alphabets. Use a YACC tool to do the same.

```
$ bison uppercase_pattern.y
$ cc uppercase_pattern.tab.c -o uppercase_pattern.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./uppercase_pattern.out` in terminal.

OUTPUT:


`./uppercase_pattern.out`
```
Enter a statement: A42fds 
Accepted
```
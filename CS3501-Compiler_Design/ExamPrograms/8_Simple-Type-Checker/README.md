# Ex.No.8 - Implement a simple type checker that checks the scope of the variables and semantic errors sfrom the given statement

```
$ cc type_checker.c -o type_checker.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./type_checker.out` in terminal.

OUTPUT:


`./type_checker.out`
```
int a, b;

int c = a + b


Enter a value for a : 5

a is : int

Enter a value for b : 3

b is : int

No Type Error
```

```
int a, b;

int c = a + b


Enter a value for a : ds

a is : AplhaNumeric

Enter a value for b : 0

b is : int

Type Error
```
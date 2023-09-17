# Ex.No.9 - Implementation of Simple Code Optimization Techniques.

```
$ cc simple_code_opt_tech.c -o simple_code_opt_tech.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./simple_code_opt_tech.out` in terminal.

OUTPUT:


`./simple_code_opt_tech.out`
```
Enter number of values: 3
Left: a
        right: 8
Left: a
        right: c+d
Left: a
        right: c+d

Intermediate Code:
a=8
a=c+d
a=c+d

After Dead code Elimination:
a       =c+d

Eliminate Common Expression:
a       =c+d

Optimized code: 
a=c+d
```
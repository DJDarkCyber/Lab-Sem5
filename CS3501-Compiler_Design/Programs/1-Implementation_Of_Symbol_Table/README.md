# Ex.No.1 - Implementation of symbol table

```
$ cc sym_tble.c -o sym_tble.out
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./sym_tble.out` in terminal.

OUTPUT:

`./sym_tble.out`
```
1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 1
Enter new symbol, datatype, length : x int 123

1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 1
Enter new symbol, datatype, length : y float 456

1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 1
Enter new symbol, datatype, length : z double 789

1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 3
Symbol  datatype        length
x       int             123
y       float           456
z       double          789

1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 4
Enter the symbol to be searched : y
Symbol found
y       float           456
1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 5
Enter the symbol to be modified : y
Symbol is found y       float           456
Enter new values for datatypes, length : long 437
Symbol entries modified

1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 3
Symbol  datatype        length
x       int             123
y       long            437
z       double          789

1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 2
Enter the symbol to be deleted : y
The symbol is deleted

1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 3
Symbol  datatype        length
x       int             123
z       long            789

1. Insert
2. Delete
3. Display
4. Search
5. Modify
6. Exit

Enter the choice : 6
```
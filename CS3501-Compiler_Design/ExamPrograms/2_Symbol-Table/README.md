# Ex.No.2 - Implementation a symbol table that involves insertion, deletion, search and modify operations using C language

```
$ cc symb.c -o symbout
```

Execution :

1. Navigate to your compiled program directory.
2. Run `./symb.out` in terminal.

OUTPUT:

`./symb.out`
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
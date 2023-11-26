# Ex.No.19 - Implement and check the error detection/error correction techniques in networks and identify the errors.

```
$ cc crc.c -o crc.out
```

Execution :

1. Open two terminals.
2. Navigate to your compiled program directory.
3. Run `./crc.out` in terminal.

OUTPUT:

`./crc.out`
```

1. CRC ENCODER
2. CRC DECODER
3. EXIT
Enter your choice: 1
Enter the length of dataword: 4
Enter the data word: 1 0 1 1
Enter the length of divisor: 3
Enter the divisor: 1 1 0

The data with zeros is:
101100
The quotient is:
1101
The remainder is:
010
The codeword is:
101110
```

```
1. CRC ENCODER
2. CRC DECODER
3. EXIT
Enter your choice: 2
Enter the length of codeword: 6
Enter the codeword: 1 0 1 1 1 0
Enter the length of divisor: 3
Enter the divisor: 1 1 0

The quotient is:
1101
The remainder is:
000
No error in the received code
```
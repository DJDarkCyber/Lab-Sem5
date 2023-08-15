# Ex.No.3c TCP - Client And Server File Transfer

```
$ cc server.c -o server.out
$ cc client.c -o client.out
```

Execution :

1. Create a file that you want to transfer.
2. Open two terminals.
3. Navigate to your compiled program directory.
4. Run `./server.out` in 1st terminal and `./client.out 127.0.0.1` in another terminal.

OUTPUT:

`./server.out`

```
Client Connected
Name of the requested file: /tmp/message
Content of the requested file
I got transferred!
```

`./client.out 127.0.0.1`

```
Enter the file name: /tmp/message

Data of the file from server:
I got transferred!
```

![Execution](https://i.postimg.cc/nc2GgHLZ/Screenshot-2023-08-15-11-21-07.png)
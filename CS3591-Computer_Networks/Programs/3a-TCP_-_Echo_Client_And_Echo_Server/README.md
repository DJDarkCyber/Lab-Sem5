# Ex.No.3a TCP - Echo client and echo server

```
$ cc server.c -o server.out
$ cc client.c -o client.out
```

Execution :

1. Open two terminals.
2. Navigate to your compiled program directory.
3. Run `./server.out` in 1st terminal and `./client.out` in another terminal.

OUTPUT:

`./server.out`
```
ECHO SERVER connected...
```

`./client.out`

```
Client: Hi

Echo Server Message: Hi

Client: How are you?

Echo Server Message: How are you?

Client: bye

Echo Server Message: bye
```

![Execution](https://i.postimg.cc/xTWNTYzh/Screenshot-2023-08-14-17-27-42.png)
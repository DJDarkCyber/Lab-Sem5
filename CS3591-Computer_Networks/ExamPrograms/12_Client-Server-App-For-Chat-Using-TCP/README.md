# Ex.No.12 - Write a program a client-server application for CHAT using TCP.

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

Client message: Hey
Server: Hi

Client message: How are you doing today?
Server: Doing fine. How about you?

Client message: Nice to hear that. I'm doing great!
Server: Great to hear that!

Client message: Good bye!
Server: bye

```

`./client.out`

```
Client: Hey

Server Message: Hi

Client: How are you doing today?

Server Message: Doing fine. How about you?

Client: Nice to hear that. I'm doing great!

Server Message: Great to hear that!

Client: Good bye!

Server Message: bye
```

![Execution](https://i.postimg.cc/c1YHZJYn/Screenshot-2023-08-14-18-14-32.png)
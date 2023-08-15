# Ex.No.4 - Simulation of DNS using UDP sockets

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

Enter your port number: 4444

Received from client: 127.0.0.1

Received
```

`./client.out`
```

Enter your port number: 4444

Enter ip address:
127.0.0.1

Sent to server.
127.0.0.1

Received from server.

Ethernet name is: google
```

[![Screenshot-2023-08-15-12-01-14.png](https://i.postimg.cc/6Q0d1ZNB/Screenshot-2023-08-15-12-01-14.png)](https://postimg.cc/f3VtVJLP)
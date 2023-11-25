#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int std, i, len, port;
    char content[100], str[100];
    char ip[50][50] = {"127.0.0.1", "127.0.0.2", "127.0.0.3", "127.0.0.4",
                       "127.0.0.5"};
    char eth[50][50] = {"google", "yahoo", "rediff", "rocket", "hotmail"};
    struct sockaddr_in ser, cli;

    printf("\nEnter your port number: ");
    scanf("%d", &port);

    if ((std = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("\nSocket not created.");
        exit(0);
    }

    bzero((char*)&ser, sizeof(ser));
    bzero((char*)&cli, sizeof(cli));
    ser.sin_family = cli.sin_family = AF_INET;
    ser.sin_port = cli.sin_port = htons(port);
    ser.sin_addr.s_addr = cli.sin_addr.s_addr = htons(INADDR_ANY);
    i = bind(std, (struct sockaddr*)&ser, sizeof(ser));

    if (i < 0) {
        printf("\nConnection problem.\n");
        exit(0);
    }

    len = sizeof(cli);

    while (1) {
        printf("\nReceived from client: ");
        recvfrom(std, content, 100, 0, (struct sockaddr*)&cli, &len);
        printf("%s\n", content);
        if (strcmp(content, "bye") == 0) break;
        for (i = 0; i < 5; i++) {
            if (!strcmp(content, ip[i])) {
                strcpy(str, "");
                printf("\nReceived\n");
                strcat(str, "Ethernet name is: ");
                strcat(str, eth[i]);
                sendto(std, str, 100, 0, (struct sockaddr*)&cli, len);
            } else if (!strcmp(content, eth[i])) {
                strcpy(str, "");
                printf("\nReceived");
                strcat(str, "IP address is: ");
                strcat(str, ip[i]);
                sendto(std, str, 100, 0, (struct sockaddr*)&cli, len);
            }
        }

        close(std);

        return (0);
    }
    
}
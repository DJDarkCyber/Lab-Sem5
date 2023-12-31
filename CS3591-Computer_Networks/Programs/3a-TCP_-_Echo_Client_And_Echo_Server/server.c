#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

#define SERV_TCP_PORT 3785


int main(int argc, char *argv[]) {
    int sockfd, new, clen;
    struct sockaddr_in serv_add, cli_add;
    char buffer[4096];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_add.sin_family = AF_INET;
    serv_add.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_add.sin_port = htons(SERV_TCP_PORT);
    bind(sockfd, (struct sockaddr*)&serv_add, sizeof(serv_add));
    listen(sockfd, 5);
    clen = sizeof(cli_add);
    new = accept(sockfd, (struct sockaddr*)&cli_add, &clen);
    printf("ECHO SERVER connected...\n");

    do {
        bzero(buffer, 4096);
        read(new, buffer, 4096);
        write(new, buffer, 4096);
    } while(strcmp(buffer, "bye\n")!=0);

    close(sockfd);
    return 0;
}
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERV_PORT 3322

int main(int argc, char **argv) {
    int i, j;
    ssize_t n;
    char filename[80], recvline[80];
    struct sockaddr_in servaddr;
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    printf("Enter the file name: ");
    scanf("%s", filename);
    write(sockfd, filename, sizeof(filename));
    printf("\nData of the file from server:\n");

    while (read(sockfd, recvline, 80) != 0) {
        puts(recvline);
    }

    return 0;
}
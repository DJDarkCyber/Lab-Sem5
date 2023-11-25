#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    int i, a, flag = 0;
    char ip1[5][32]={"192.168.0.5","192.168.0.6","192.168.0.8","192.168.0.9"};
    char mac1[5][48] = {"2c:41:38:9a:75:f5","2c:41:38:9a:75:f6","2c:41:38:9a:75:f7","2c:41:38:9a:75:f8"};
    char ip[32],mac[48];
    printf("\nThe ARP table is \n");
    printf("\nIP address\t MAC address");

    for (i = 0; i < 5; i++ ) {
        printf("\n%s\t%s", ip1[i], mac1[i]);
    }

    printf("\n1. ARP\n2. RARP\n3. EXIT\nEnter your choice : ");
    scanf("%d", &a);
    
    switch(a) {

        case 1:
            printf("\nEnter IP address: ");
            scanf("%s", &ip);
            for (i = 0; i < 5; i++ ) {
                if( strcmp(ip, ip1[i]) == 0 ) {
                    printf("\n mac addr is %s",mac1[i]);
                    printf("\n");
                    flag=1;
                }
            }

            if (flag == 0) {
                printf("\nHost not found in ARP table");
            }

            break;
        
        case 2:
            printf("\nEnter MAC address: ");
            scanf("%s", &mac);

            for (i = 0; i < 5; i++ ) {
                if ( strcmp(mac, mac1[i]) == 0 ) {
                    printf("\nIP addr is %s", ip1[i]);
                    printf("\n");
                    flag = 1;
                }
            }

            if (flag == 0)
                printf("\nHost not found in ARP table.");
            
            break;

        case 3:
            printf("EXIT");
    }

    return 0;
}
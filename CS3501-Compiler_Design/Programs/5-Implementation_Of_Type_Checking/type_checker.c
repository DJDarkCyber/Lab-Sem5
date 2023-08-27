#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


char* type(char[], int);


void main() {
    char a[10], b[10], mess[20], mess1[20];
    int i, l;
    printf("\n\nint a, b;\n\nint c = a + b\n");
    printf("\n\nEnter a value for a : ");
    scanf("%s", a);
    l = strlen(a);
    printf("\na is : ");
    strcpy(mess, type(a, l));
    printf("%s", mess);
    printf("\n\nEnter a value for b : ");
    scanf("%s", b);
    l = strlen(b);
    printf("\nb is : ");
    strcpy(mess1, type(b, l));
    printf("%s", mess1);

    if( strcmp(mess, "int") == 0 && strcmp(mess1, "int") == 0) {
        printf("\n\nNo Type Error");
    }
    else{
        printf("\n\nType Error");
    }

}


char* type(char x[], int m) {
    int i;
    static char mes[20];
    
    for(i=0; i<m; i++) {

        if (isalpha(x[i])) {
            strcpy(mes, "AplhaNumeric");
            goto x;
        }

        else if ( x[i] == '.' ) {
            strcpy(mes, "float");
            goto x;
        }

        strcpy(mes, "int");
        x:;
    
    }

    return mes;
}
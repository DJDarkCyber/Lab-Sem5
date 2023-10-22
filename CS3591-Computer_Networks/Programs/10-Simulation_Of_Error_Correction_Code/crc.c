#include <stdio.h>

int *mod2div(int n[], int div[], int clength, int divlength);

int f[20];

int main() {
    int j, i, a, temp2, clength, dlength, divlength, c[20], n[20], div[50];
    a = temp2 = 0;
    int *f = NULL;

    printf("\n1. CRC ENCODER\n2. CRC DECODER\n3. EXIT\nEnter your choice: ");
    scanf("%d", &a);

    switch (a) {
        case 1:
            printf("Enter the length of dataword: ");
            scanf("%d", &dlength);
            printf("Enter the data word: ");
            for (i = 0; i < dlength; i++) {
                scanf("%d", &n[i]);
            }
            for (i = 0; i < dlength; i++) {
                c[i] = n[i];
            }
            printf("Enter the length of divisor: ");
            scanf("%d", &divlength);
            printf("Enter the divisor: ");
            for (i = 0; i < divlength; i++) {
                scanf("%d", &div[i]);
            }
            clength = dlength + divlength - 1;
            for (i = dlength; i < clength; i++) {
                n[i] = 0;
            }
            printf("\nThe data with zeros is:\n");
            for (i = 0; i < clength; i++) {
                printf("%d", n[i]);
            }
            f = mod2div(n, div, clength, divlength);
            for (i = dlength; i < clength; i++) {
                c[i] = n[i];
            }
            printf("\nThe codeword is:\n");
            for (i = 0; i < clength; i++) {
                printf("%d", c[i]);
            }
            break;
        case 2:
            printf("Enter the length of codeword: ");
            scanf("%d", &clength);
            printf("Enter the codeword: ");
            for (i = 0; i < clength; i++) {
                scanf("%d", &n[i]);
            }
            printf("Enter the length of divisor: ");
            scanf("%d", &divlength);
            printf("Enter the divisor: ");
            for (i = 0; i < divlength; i++) {
                scanf("%d", &div[i]);
            }
            f = mod2div(n, div, clength, divlength);
            for (j = 0; j < divlength; j++) {
                temp2 = temp2 + f[j];
            }
            if (temp2 == 0) {
                printf("\nNo error in the received code\n");
            } else {
                printf("\nError occurs in the received code\n");
            }
            break;
        case 3:
            printf("EXIT\n");
            break;
    }
    return 0;
}

// Function description mod2div
int *mod2div(int n[], int div[], int clength, int divlength) {
    int i, M, temp, dlength, j, quot[20];
    dlength = clength - divlength + 1;

    for (i = 0; i < dlength; i++) {
        temp = i;
        if (n[i] == 1) {
            quot[i] = 1;
            for (j = 0; j < divlength; j++) {
                M = n[temp] ^ div[j];
                n[temp] = f[j] = M;
                temp = temp + 1;
            }
        } else {
            quot[i] = 0;
            for (j = 0; j < divlength; j++) {
                f[j] = n[i + j];
            }
        }
    }
    printf("\nThe quotient is:\n");
    for (j = 0; j < dlength; j++) {
        printf("%d", quot[j]);
    }
    printf("\nThe remainder is:\n");
    for (j = 0; j < divlength; j++) {
        printf("%d", f[j]);
    }
    return f;
}

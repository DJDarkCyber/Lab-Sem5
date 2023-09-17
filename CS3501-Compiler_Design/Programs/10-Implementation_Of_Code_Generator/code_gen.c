#include <stdio.h>

int main() {
    int n, i, j;
    char a[50][50];

    printf("\nEnter the number of intermediate codes: ");
    scanf("%d", &n);

    getchar();

    for (i = 0; i < n; i++) {
        printf("Enter the three address code %d: ", i + 1);

        for (j = 0; j < 6; j++) {
            a[i][j] = getchar();
        }
        getchar();
    }

    printf("\nThe Generated code:\n");

    for (i = 0; i < n; i++) {
        printf("\nMOV %c,R%d", a[i][3], i);

        if (a[i][4] == '-') {
            printf("\nSUB %c,R%d", a[i][5], i);
        } else if (a[i][4] == '+') {
            printf("\nADD %c,R%d", a[i][5], i);
        } else if (a[i][4] == '*') {
            printf("\nMUL %c,R%d", a[i][5], i);
        } else if (a[i][4] == '/') {
            printf("\nDIV %c,R%d", a[i][5], i);
        }

        printf("\nMOV R%d,%c", i, a[i][1]);
        printf("\n");
    }

    return 0;
}

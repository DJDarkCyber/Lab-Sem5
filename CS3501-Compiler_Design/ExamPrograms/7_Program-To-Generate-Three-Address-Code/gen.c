#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pm();
void plus();
void div_op();
void strrev(char *str);

int i, ch, j, l;
char ex[10], ex1[10], exp1[10], ex2[10];

int main() {
    while (1) {
        printf("\n 1. Assignment\n 2. Arithmetic\n 3. Exit\n ENTER THE CHOICE:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n Enter the expression with assignment operator:");
                scanf("%s", ex1);
                l = strlen(ex1);
                ex2[0] = '\0';
                i = 0;

                while (ex1[i] != '=') {
                    i++;
                }

                strncat(ex2, ex1, i);
                strrev(ex1);
                exp1[0] = '\0';
                strncat(exp1, ex1, l - (i + 1));
                strrev(exp1);
                printf("3 address code:\n temp=%s \n %s=temp\n", exp1, ex2);
                break;

            case 2:
                printf("\n Enter the expression with arithmetic operator:");
                scanf("%s", ex);
                strcpy(ex1, ex);
                l = strlen(ex1);
                exp1[0] = '\0';

                for (i = 0; i < l; i++) {
                    if (ex1[i] == '+' || ex1[i] == '-') {
                        if (ex1[i + 2] == '/' || ex1[i + 2] == '*') {
                            pm();
                            break;
                        } else {
                            plus();
                            break;
                        }
                    } else if (ex1[i] == '/' || ex1[i] == '*') {
                        div_op();
                        break;
                    }
                }
                break;

            case 3:
                exit(0);
                break;
        }
    }
    return 0;
}

void pm() {
    strrev(exp1);
    j = l - i - 1;
    strncat(exp1, ex1, j);
    strrev(exp1);
    printf("3 address code:\n temp=%s\n temp1=%c%c temp\n", exp1, ex1[j + 2], ex1[j]);
}

void div_op() {
    strncat(exp1, ex1, i + 2);
    printf("3 address code:\n temp=%s\n temp1=temp%c%c\n", exp1, ex1[l + 2], ex1[i + 3]);
}

void plus() {
    strncat(exp1, ex1, i + 2);
    printf("3 address code:\n temp=%s\n temp1=temp%c%c\n", exp1, ex1[l + 2], ex1[i + 3]);
}

// Tool

void strrev(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}
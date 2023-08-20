#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void main() { 
    char in[50], temp[50];
    int i = 0, j = 0;
    printf("Enter the expression: ");
    gets(in);
    printf("\nKeyword \t Identifier \t Constant \t Operator \t sp. Character \n");

    while(in[i] != '\0') {

        if ( isalpha(in[i]) ) {

            while ( isalpha(in[i]) || isdigit(in[i]) )
                temp[j++] = in[i++];
                
            temp[j] = '\0';

            if (strcmp(temp, "if") == 0 || strcmp(temp, "int") == 0 || strcmp(temp, "char") == 0
            || strcmp(temp, "else") == 0 || strcmp(temp, "float") == 0 || strcmp(temp, "do")
            == 0 || strcmp(temp, "for") == 0 || strcmp(temp, "while") == 0)
                printf("\n%s", temp);
            else
                printf("\n\t\t\t%s", temp);
            
        }
        else if (isdigit(in[i])) {
        
            while (isdigit(in[i]))
                temp[j++] = in[i++];
        
        temp[j] = '\0';
        printf("\n\t\t\t\t\t%s", temp);
        }
        else if (in[i] =='+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '>' || in[i] == '<'
        || in[i] == '=' || in[i] == '!')
            printf("\n\t\t\t\t\t\t%c", in[i++]);
        else if (in[i] ==';' || in[i] == ':' || in[i] == '(' || in[i] == ')' || in[i] == '{' || in[i] == '}' || in[i] == '.')
            printf("\n\t\t\t\t\t\t\t\t%c", in[i++]);
        else if (in[i] == ' ')
            i++;
        else
            i++;
        
        j=0;

    }

}
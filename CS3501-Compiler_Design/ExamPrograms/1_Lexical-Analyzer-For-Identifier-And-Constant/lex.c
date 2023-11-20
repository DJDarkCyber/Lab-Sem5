#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main() {
	char in[50], temp[50];
	int i = 0, j = 0;
	printf("Enter the expression : ");
	gets(in);
	printf("\nIdentifier \t Constant\n");

	while(in[i] != '\0') {
		if ( isalpha(in[i]) ) {
				
			while ( isalpha(in[i]) || isdigit(in[i]) ) 
				temp[j++] = in[i++];

			temp[j] = '\0';
			printf("%s\n", temp);
				
		}
		else if (isdigit(in[i])) {
			while (isdigit(in[i]))
				temp[j++] = in[i++];

			temp[j] = '\0';
			printf("\t\t\t%s\n", temp);
		}
		else if (in[i] == ' ')
			i++;
		else
			i++;

		j=0;
	}
}
		


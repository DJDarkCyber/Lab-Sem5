#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char result;
    char operand1;
    char operand2;
} ThreeAddressCode;

void convertToAssembly(ThreeAddressCode *code, int numInstructions) {
    for (int i = 0; i < numInstructions; i++) {
        printf("; Assembly code for three-address code %d\n", i + 1);

        char result = code[i].result;
        char operand1 = code[i].operand1;
        char operand2 = code[i].operand2;

        printf("MOV %c, %c\n", operand1, result);
        printf("ADD %c, %c, %c\n", operand2, result, result);

        printf("\n");
    }
}

int main() {
    int numInstructions;

    printf("Enter the number of three-address code instructions: ");
    scanf("%d", &numInstructions);

    ThreeAddressCode *code = (ThreeAddressCode *)malloc(numInstructions * sizeof(ThreeAddressCode));

    printf("Enter three-address code:\n");
    for (int i = 0; i < numInstructions; i++) {
        printf("Instruction %d: ", i + 1);
        scanf(" t%c = t%c + t%c", &code[i].result, &code[i].operand1, &code[i].operand2);

        // Clear the input buffer
        while (getchar() != '\n');
    }

    printf("\nAssembly code:\n");
    convertToAssembly(code, numInstructions);

    free(code);

    return 0;
}

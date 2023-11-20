#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack implementation for operands
#define MAX_STACK_SIZE 50

typedef struct {
    int top;
    char items[MAX_STACK_SIZE];
} Stack;

void push(Stack *stack, char item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++(stack->top)] = item;
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[(stack->top)--];
}

// Function to generate machine code from postfix notation
void generateMachineCode(char postfix[]) {
    Stack stack = { .top = -1 };
    int i = 0;
    int regCount = 0;

    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (isalnum(symbol)) {
            push(&stack, symbol);
        } else {
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);

            printf("MOV %c,R%d\n", operand1, regCount);
            regCount++;

            switch (symbol) {
                case '+':
                    printf("ADD %c,R%d\n", operand2, regCount);
                    break;
                case '-':
                    printf("SUB %c,R%d\n", operand2, regCount);
                    break;
                case '*':
                    printf("MUL %c,R%d\n", operand2, regCount);
                    break;
                case '/':
                    printf("DIV %c,R%d\n", operand2, regCount);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }

            push(&stack, 'R' + regCount - 1);
        }

        i++;
    }

    printf("Machine code generation completed.\n");
}

int main() {
    char postfix[50];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    generateMachineCode(postfix);

    return 0;
}

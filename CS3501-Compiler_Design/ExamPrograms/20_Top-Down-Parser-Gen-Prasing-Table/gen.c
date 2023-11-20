#include <stdio.h>
#include <ctype.h>

// Global variables
char input[50];
int currentTokenIndex = 0;
int errorFlag = 0;

// Function to match a terminal symbol
void match(char expectedToken) {
    if (input[currentTokenIndex] == expectedToken) {
        currentTokenIndex++;
    } else {
        printf("Error: Expected '%c', found '%c'\n", expectedToken, input[currentTokenIndex]);
        errorFlag = 1;
    }
}

// Function for non-terminal E
void E();

// Function for non-terminal T
void T();

// Function for non-terminal F
void F();

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);

    // Reset global variables
    currentTokenIndex = 0;
    errorFlag = 0;

    // Start parsing
    E();

    // Check for successful parsing
    if (!errorFlag && input[currentTokenIndex] == '\0') {
        printf("Parsing Successful: Valid Arithmetic Expression\n");
    } else {
        printf("Parsing Failed: Invalid Arithmetic Expression\n");
    }

    return 0;
}

// Function for non-terminal E
void E() {
    T();
    while (input[currentTokenIndex] == '+' || input[currentTokenIndex] == '-') {
        char op = input[currentTokenIndex];
        match(op);
        T();
    }
}

// Function for non-terminal T
void T() {
    F();
    while (input[currentTokenIndex] == '*' || input[currentTokenIndex] == '/') {
        char op = input[currentTokenIndex];
        match(op);
        F();
    }
}

// Function for non-terminal F
void F() {
    if (isdigit(input[currentTokenIndex])) {
        match(input[currentTokenIndex]);
    } else if (input[currentTokenIndex] == '(') {
        match('(');
        E();
        match(')');
    } else {
        printf("Error: Unexpected token '%c'\n", input[currentTokenIndex]);
        errorFlag = 1;
    }
}

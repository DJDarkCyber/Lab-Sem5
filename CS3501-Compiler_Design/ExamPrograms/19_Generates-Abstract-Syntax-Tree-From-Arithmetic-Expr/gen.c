#include <stdio.h>
#include <stdlib.h>

// Node structure for the abstract syntax tree
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the abstract syntax tree
TreeNode* buildAST(char *expression, int *index) {
    TreeNode *root = NULL;
    TreeNode *currentNode = NULL;

    while (expression[*index] != '\0') {
        if (expression[*index] >= '0' && expression[*index] <= '9') {
            // Operand
            currentNode = createNode(expression[*index]);
        } else {
            // Operator
            TreeNode *leftOperand = currentNode;
            currentNode = createNode(expression[*index]);

            (*index)++; // Move to the next character

            // Recursively build the right operand
            currentNode->right = buildAST(expression, index);
            currentNode->left = leftOperand;
        }

        (*index)++; // Move to the next character
    }

    return currentNode;
}

// Function to print the abstract syntax tree (in-order traversal)
void printAST(TreeNode *root) {
    if (root != NULL) {
        printAST(root->left);
        printf("%c ", root->data);
        printAST(root->right);
    }
}

int main() {
    char expression[50];

    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);

    int index = 0;
    TreeNode *root = buildAST(expression, &index);

    printf("Abstract Syntax Tree (in-order traversal):\n");
    printAST(root);

    return 0;
}

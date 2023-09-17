#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Heap {
    int data;
    struct Heap *next;
} node;

node *create();
node *get_node();
void display(node *);
node *search(node *, int);
node *insert(node *);
node *insert_head(node *);
void insert_after(node *);
void insert_last(node *);
node *get_prev(node *, int);
void dele(node **);

int main() {
    int choice, val;
    char ans;
    node *head = NULL;

    do {
        printf("\n Program to perform various operations on heap using dynamic memory management");
        printf("\n 1. Create");
        printf("\n 2. Display");
        printf("\n 3. Insert an element in the list");
        printf("\n 4. Delete an element from the list");
        printf("\n 5. Quit");
        printf("\n Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = create();
                break;

            case 2:
                display(head);
                break;

            case 3:
                head = insert(head);
                break;

            case 4:
                dele(&head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice, try again");
        }
    } while (choice != 5);

    return 0;
}

node *create() {
    node *temp, *new_node, *head;
    int val, flag;
    char ans = 'y';

    temp = NULL;
    flag = TRUE;

    do {
        printf("\n Enter the element: ");
        scanf("%d", &val);

        new_node = get_node();
        if (new_node == NULL)
            printf("\n Memory is not allocated");

        new_node->data = val;

        if (flag == TRUE) {
            head = new_node;
            temp = head;
            flag = FALSE;
        } else {
            temp->next = new_node;
            temp = new_node;
        }

        printf("\n Do you want to enter more elements? (y/n)");
        scanf(" %c", &ans); // Note the space before %c to consume the newline character
    } while (ans == 'y');

    printf("\n The list is created");
    return head;
}

node *get_node() {
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

void display(node *head) {
    node *temp;
    temp = head;

    if (temp == NULL) {
        printf("\n The list is empty\n");
        return;
    }

    printf("\n List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

node *search(node *head, int key) {
    node *temp;
    temp = head;

    if (temp == NULL) {
        printf("\nThe linked list is empty\n");
        return NULL;
    }

    while (temp != NULL) {
        if (temp->data == key) {
            printf("\n The element %d is present in the list\n", key);
            return temp;
        }
        temp = temp->next;
    }

    printf("\nThe element %d is not present in the list\n", key);
    return NULL;
}

node *insert(node *head) {
    int choice;

    printf("\n 1. Insert a node as a head node");
    printf("\n 2. Insert a node as the last node");
    printf("\n 3. Insert a node at an intermediate position in the list");
    printf("\n Enter your choice for insertion of a node: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head = insert_head(head);
            break;

        case 2:
            insert_last(head);
            break;

        case 3:
            insert_after(head);
            break;
    }

    return head;
}

node *insert_head(node *head) {
    node *New, *temp;
    New = get_node();

    printf("\n Enter the element which you want to insert: ");
    scanf("%d", &New->data);

    if (head == NULL)
        head = New;
    else {
        temp = head;
        New->next = temp;
        head = New;
    }

    return head;
}

void insert_last(node *head) {
    node *New, *temp;
    New = get_node();

    printf("\n Enter the element which you want to insert: ");
    scanf("%d", &New->data);

    if (head == NULL)
        head = New;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = New;
        New->next = NULL;
    }
}

void insert_after(node *head) {
    int key;
    node *New, *temp;

    New = get_node();

    printf("\n Enter the element after which you want to insert: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("\nEnter the element which you want to insert: ");
            scanf("%d", &New->data);
            New->next = temp->next;
            temp->next = New;
            return;
        }
        temp = temp->next;
    }

    printf("\nThe element %d is not found in the list. Insertion failed.\n", key);
}

node *get_prev(node *head, int val) {
    node *temp, *prev;
    temp = head;
    prev = NULL;

    while (temp != NULL) {
        if (temp->data == val)
            return prev;
        prev = temp;
        temp = temp->next;
    }

    return NULL;
}

void dele(node **head) {
    int key;
    node *temp, *prev;

    temp = *head;

    if (temp == NULL) {
        printf("\n The list is empty\n");
        return;
    }

    printf("\n Enter the element you want to delete: ");
    scanf("%d", &key);

    temp = search(*head, key);

    if (temp != NULL) {
        prev = get_prev(*head, key);

        if (prev != NULL) {
            prev->next = temp->next;
            free(temp);
        } else {
            *head = temp->next;
            free(temp);
        }

        printf("\n Element is deleted\n");
    }
}

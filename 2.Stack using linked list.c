#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Stack is full.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);

    (*top_ref)    = new_node;
}

int pop(struct Node** top_ref) {
    int popped_data;
    struct Node* temp;

    if (*top_ref == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }

    temp = *top_ref;
    popped_data = temp->data;

    *top_ref = temp->next;

    free(temp);

    return popped_data;
}

void display(struct Node* top_ref) {
    if (top_ref == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top of Stack: ");
    while (top_ref != NULL) {
        printf("%d ", top_ref->data);
        top_ref = top_ref->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int choice, item;

    while (1) {
        printf("\n\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &item);
                push(&top, item);
                break;
            case 2:
                printf("%d popped from stack\n", pop(&top));
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
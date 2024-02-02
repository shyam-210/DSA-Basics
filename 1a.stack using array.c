#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

int isFull() {
    return top == MAX_SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    top++;
    stack[top] = item;
    printf("Pushed: %d\n", item);
}

int pop() {
    int item;

    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    item = stack[top];
    top--;

    printf("Popped: %d\n", item);
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

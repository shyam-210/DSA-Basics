#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void enqueue(struct Node** rear_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*rear_ref == NULL) {
        *rear_ref = new_node;
        return;
    }

    struct Node* temp = *rear_ref;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    return;
}

int dequeue(struct Node** front_ref, struct Node** rear_ref) {
    if (*front_ref == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct Node* temp = *front_ref;
    int popped_data = temp->data;

    if (*front_ref == *rear_ref) {
        *rear_ref = NULL;
    }

    *front_ref = temp->next;
    free(temp);

    return popped_data;
}

void display(struct Node* front_ref) {
    if (front_ref == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front of Queue: ");
    while (front_ref != NULL) {
        printf("%d ", front_ref->data);
        front_ref = front_ref->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, item;

    while (1) {
        printf("\n\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &item);
                enqueue(&rear, item);
                if (front == NULL)
                    front = rear;
                break;
            case 2:
                printf("%d dequeued from queue\n", dequeue(&front, &rear));
                if (front == NULL)
                    rear = NULL;
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
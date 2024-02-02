#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Structure to represent a heap (binary min-heap in this case)
struct MinHeap {
    int* array;
    int size;
    int capacity;
};

// Function to create a new Min Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    if (heap == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    heap->array = (int*)malloc(capacity * sizeof(int));
    if (heap->array == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with the given index
void heapify(struct MinHeap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->array[leftChild] < heap->array[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap->size && heap->array[rightChild] < heap->array[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Function to insert a new element into the Priority Queue
void insert(struct MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Priority Queue is full. Cannot insert %d\n", value);
        return;
    }

    // Insert the new element at the end of the heap
    int i = heap->size;
    heap->array[i] = value;
    heap->size++;

    // Fix the min-heap property by bubbling up the new element
    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete a specific element from the Priority Queue
void deleteElement(struct MinHeap* heap, int value) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->array[i] == value) {
            break;
        }
    }

    if (i == heap->size) {
        printf("Element %d not found in the Priority Queue.\n", value);
        return;
    }

    // Replace the found element with the last element
    heap->array[i] = heap->array[heap->size - 1];
    heap->size--;

    // Fix the min-heap property by heapifying the element
    heapify(heap, i);

    printf("Element %d deleted from the Priority Queue.\n", value);
}

// Function to search for a specific element in the Priority Queue
void search(struct MinHeap* heap, int value) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->array[i] == value) {
            printf("Element %d found at index %d in the Priority Queue.\n", value, i);
            return;
        }
    }

    printf("Element %d not found in the Priority Queue.\n", value);
}

// Function to display the Priority Queue
void display(struct MinHeap* heap) {
    printf("Priority Queue: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

// Function to free the memory used by the Priority Queue
void freePriorityQueue(struct MinHeap* heap) {
    free(heap->array);
    free(heap);
}

int main() {
    int capacity, choice, value;

    printf("Enter the capacity of the Priority Queue: ");
    scanf("%d", &capacity);

    struct MinHeap* priorityQueue = createMinHeap(capacity);

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                insert(priorityQueue, value);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &value);
                deleteElement(priorityQueue, value);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &value);
                search(priorityQueue, value);
                break;
            case 4:
                display(priorityQueue);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    // Free the memory used by the Priority Queue before exiting
    freePriorityQueue(priorityQueue);

    return 0;
}

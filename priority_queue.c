/*Implement a Priority Queue using arrays with the operations: 
    a.Insert elements into the queue 
    b.Delete elements from the queue 
    c.Display the contents of the queue after each operation.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up (for insert)
void heapifyUp(int i) {
    while (i > 1 && heap[i / 2] < heap[i]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

// Heapify down (for delete)
void heapifyDown(int i) {
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;

    if (left <= size && heap[left] > heap[largest])
        largest = left;

    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}

// Insert element into priority queue
void insert(int value) {
    if (size == MAX - 1) {
        printf("Priority Queue is full!\n");
        return;
    }
    size++;
    heap[size] = value;
    heapifyUp(size);
    printf("Inserted %d into the queue.\n", value);
}

// Delete max (highest priority element)
void deleteMax() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Deleted element: %d\n", heap[1]);
    heap[1] = heap[size];
    size--;
    heapifyDown(1);
}

// Display contents of the queue
void display() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Driver program
int main() {
    int choice, value;

    while (1) {
        printf("\nPriority Queue Operations (Max Heap):\n");
        printf("1. Insert\n2. Delete Max\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            display();
            break;
        case 2:
            deleteMax();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

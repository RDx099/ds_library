#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void printMenu() {
    printf("\nQueue Operations Menu:\n");
    printf("1. Enqueue \n");
    printf("2. Dequeue \n");
    printf("3. Front \n");
    printf("4. Traverse\n");
    printf("5. Reverse \n");
    printf("6. Is Full? - Check if the queue is full (1=yes, 0=no)\n");
    printf("7. Is Empty? - Check if the queue is empty (1=yes, 0=no)\n");
    printf("8. Exit - Exit the program\n");
    printf("Enter your choice (1-8): ");
}

int main() {
    int capacity;
    char line[256];

    printf("Enter the capacity of the queue (positive integer): ");
    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            return 1;
        }
        if (sscanf(line, "%d", &capacity) != 1 || capacity <= 0) {
            printf("Invalid capacity. Please enter a positive integer: ");
            continue;
        }
        break;
    }

    Queue* q = createQueue(capacity);
    if (!q) {
        printf("Failed to create queue. Exiting.\n");
        return 1;
    }

    int choice, value;
    while (1) {
        printMenu();

        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            freeQueue(q);
            return 1;
        }
        if (sscanf(line, "%d", &choice) != 1 || choice < 1 || choice > 8) {
            printf("Invalid choice. Please enter a number between 1 and 8.\n\n");
            continue;
        }

        switch (choice) {
            case 1: {
                printf("Enter values to enqueue (space-separated integers): ");
                if (fgets(line, sizeof(line), stdin) == NULL) {
                    printf("Error reading input.\n\n");
                    break;
                }

                int pos = 0, read, enqCount = 0;
                int noInput = 1;

                while (sscanf(line + pos, "%d%n", &value, &read) == 1) {
                    noInput = 0;
                    if (isFullQueue(q)) {
                        printf("Queue is full. Cannot enqueue %d.\n", value);
                        break;
                    } else {
                        enqueue(q, value);
                        enqCount++;
                    }
                    pos += read;
                }
                if (noInput) {
                    printf("No valid integers entered to enqueue.\n");
                } else if (enqCount > 0) {
                    printf("Enqueued %d value(s) successfully.\n", enqCount);
                }
                printf("\n");
                break;
            }
            case 2:
                if (isEmptyQueue(q)) {
                    printf("Queue is empty. Cannot dequeue.\n\n");
                } else {
                    value = dequeue(q);
                    printf("Dequeued %d\n\n", value);
                }
                break;
            case 3:
                if (isEmptyQueue(q)) {
                    printf("Queue is empty.\n\n");
                } else {
                    printf("Front element: %d\n\n", front(q));
                }
                break;
            case 4:
                if (isEmptyQueue(q)) {
                    printf("Queue is empty.\n\n");
                } else {
                    traverseQueue(q);
                    printf("\n");
                }
                break;
            case 5:
                if (isEmptyQueue(q)) {
                    printf("Queue is empty. Nothing to reverse.\n\n");
                } else {
                    reverseQueue(q);
                    printf("Queue reversed.\n\n");
                }
                break;
            case 6:
                printf("Is full? %d\n\n", isFullQueue(q));
                break;
            case 7:
                printf("Is empty? %d\n\n", isEmptyQueue(q));
                break;
            case 8:
                freeQueue(q);
                printf("Exiting... Goodbye!\n");
                return 0;
        }
    }
}
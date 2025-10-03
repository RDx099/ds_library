//
// Created by rahul on 06-09-2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/queue.h"

// Internal Queue structure
struct Queue {
    int* arr;
    int front, rear, capacity;
};

// Creates a Queue with the specified capacity
Queue* createQueue(int capacity) {
    if (capacity <= 0) return NULL;
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) return NULL;
    queue->arr = (int*)malloc(sizeof(int) * capacity);
    if (!queue->arr) {
        free(queue);
        return NULL;
    }
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Adds a value to the rear of the Queue
void enqueue(Queue* queue, int value) {
    if (!queue || isFullQueue(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = value;
    if (queue->front == -1) queue->front = 0;
}

// Removes and returns the value at the front of the Queue
int dequeue(Queue* queue) {
    if (!queue || isEmptyQueue(queue)) return INT_MIN;
    int val = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return val;
}

// Returns the value at the front without removing it
int front(Queue* queue) {
    if (!queue || isEmptyQueue(queue)) return INT_MIN;
    return queue->arr[queue->front];
}

// Checks if the Queue is empty
int isEmptyQueue(Queue* queue) {
    return !queue || queue->front == -1;
}

// Checks if the Queue is full
int isFullQueue(Queue* queue) {
    return !queue || (queue->rear + 1) % queue->capacity == queue->front;
}

// Traverses the Queue, printing all elements for debugging (front to rear)
void traverseQueue(Queue* queue) {
    if (!queue || isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->arr[i]);
        if (i == queue->rear) break;
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

// Frees the Queue and its internal data
void freeQueue(Queue* queue) {
    if (!queue) return;
    free(queue->arr);
    free(queue);
}

// Reverses the Queue in-place using a stack
void reverseQueue(Queue* queue) {
    if (!queue || isEmptyQueue(queue)) return;
    int* stack = (int*)malloc(sizeof(int) * queue->capacity);
    if (!stack) return;
    int top = -1;
    // Dequeue all elements to stack
    while (!isEmptyQueue(queue)) {
        stack[++top] = dequeue(queue);
    }
    // Enqueue back from stack
    while (top >= 0) {
        enqueue(queue, stack[top--]);
    }
    free(stack);
}

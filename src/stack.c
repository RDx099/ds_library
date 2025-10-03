//
// Created by rahul on 06-09-2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "stack.h"

// Definition of the opaque struct
//Created by Deepanshu
struct Stack {
    int *data;
    int top;
    int capacity;
};

// Creates a Stack with the specified capacity
// Created by Ritika and Shivam
Stack* createStack(int capacity) {
    if (capacity <= 0) return NULL;

    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->data = (int*)malloc(sizeof(int) * capacity);
    if (!stack->data) {
        free(stack);
        return NULL;
    }

    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Pushes a value onto the Stack
// Created by Navpreet Kaur, Sanjana
void push(Stack* stack, int value) {
    if (!stack || isFullStack(stack)) return;
    stack->data[++stack->top] = value;
}

// Pops the top value from the Stack
int pop(Stack* stack) {
    if (!stack || isEmptyStack(stack)) return INT_MIN;
    return stack->data[stack->top--];
}

// Returns the top value without removing it
int peek(Stack* stack) {
    if (!stack || isEmptyStack(stack)) return INT_MIN;
    return stack->data[stack->top];
}

// Checks if the Stack is empty
int isEmptyStack(Stack* stack) {
    if (!stack) return 1;
    return stack->top == -1;
}

// Checks if the Stack is full
int isFullStack(Stack* stack) {
    if (!stack) return 0;
    return stack->top == stack->capacity - 1;
}

// Traverses the Stack, printing all elements (top to bottom)
// Created by Nitin,Harleen
void traverseStack(Stack* stack) {
    if (!stack) {
        printf("Stack is NULL\n");
        return;
    }

    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Frees the Stack and its internal data
//Created by Sanket
void freeStack(Stack* stack) {
    if (!stack) return;
    free(stack->data);
    free(stack);
}

// Evaluates a postfix expression using a Stack
//Created by Rishav and Priyanshu
int evaluatePostfix(const char* expr) {
    if (!expr) return INT_MIN;

    Stack* stack = createStack(100); // Adjust size as needed
    if (!stack) return INT_MIN;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            // Convert single digit character to int
            push(stack, ch - '0');
        } else {
            int val2 = pop(stack);
            int val1 = pop(stack);

            if (val1 == INT_MIN || val2 == INT_MIN) {
                freeStack(stack);
                return INT_MIN; // Invalid expression
            }
// Created by Sanika and Deepanshu
            int result;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/':
                    if (val2 == 0) {
                        freeStack(stack);
                        return INT_MIN; // Divide by zero
                    }
                    result = val1 / val2;
                    break;
                default:
                    freeStack(stack);
                    return INT_MIN; // Unsupported operator
            }
            push(stack, result);
        }
    }

    int finalResult = pop(stack);
    if (!isEmptyStack(stack)) {
        freeStack(stack);
        return INT_MIN; // Extra operands, invalid expression
    }

    freeStack(stack);
    return finalResult;
}


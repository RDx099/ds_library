//
// Created by rahul on 06-09-2025.
//
#include "recursion.h"
#include <stdio.h>

// Computes factorial of a number recursively
//Created by Nishika
int factorial(int n) {
    if (n < 0) return -1;
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Computes nth Fibonacci number recursively
//Created by Namita
int fibonacci(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Solves Tower of Hanoi and visualizes moves
//Created by Naveen Saini, Payal, Jaspreet kaur 
void towerOfHanoi(int n, Stack* source, Stack* auxiliary, Stack* destination, int* moveCount) {
    if (n <= 0) return;
    towerOfHanoi(n - 1, source, destination, auxiliary, moveCount);
    int disk = pop(source);
    push(destination, disk);
    (*moveCount)++;
    printf("Move disk %d from source to destination\n", disk);
    towerOfHanoi(n - 1, auxiliary, source, destination, moveCount);
}

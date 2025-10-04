// Test case checked by - Namita,Nishika,Naveen Saini,Payal,Jaspreet kaur


#include "recursion.h"
#include <stdio.h>
#include "..//src/recursion.c"

int main() {
void testRecursionFunctions() {
    printf("Testing factorial:\n");
    printf("factorial(5) = %d\n", factorial(5)); // Expected: 120

    printf("\nTesting fibonacci:\n");
    printf("fibonacci(7) = %d\n", fibonacci(7)); // Expected: 13

    printf("\nTesting Tower of Hanoi:\n");
    Stack source, auxiliary, destination;
    int moveCount = 0;
    initStack(&source);
    initStack(&auxiliary);
    initStack(&destination);

    // Push disks onto source stack (largest disk at bottom)
    push(&source, 3);
    push(&source, 2);
    push(&source, 1);

    towerOfHanoi(3, &source, &auxiliary, &destination, &moveCount);
    printf("Total moves: %d\n", moveCount);
}
 return 0;
}


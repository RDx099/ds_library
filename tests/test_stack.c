#include <stdio.h>
#include "../include/stack.h"
#include <limits.h>

int main() {
    Stack* stack = createStack(3);
    if (!stack) return 1;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    traverseStack(stack);

    printf("Peek: %d\n", peek(stack));
    printf("Pop: %d\n", pop(stack));
    traverseStack(stack);

    freeStack(stack);

    // Test postfix evaluation
    const char* expr = "23+5*";  // (2 + 3) * 5 = 25
    int result = evaluatePostfix(expr);
    printf("Postfix '%s' = %d\n", expr, result == INT_MIN ? -1 : result);

    return 0;
}

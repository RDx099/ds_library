#include <stdio.h>
#include <stdlib.h>
#include"..//src/sorting.c"

int main() {
    int original[] = {34, 12, 78, 12, 56, 34, 89, 5, 12};
    int n = sizeof(original) / sizeof(original[0]);

    Array arr;
    arr.data = malloc(n * sizeof(int));
    arr.size = n;
    //Test cases checked by - Prakash Tiwari, Prince Sagwal, Raghav Dadwal, Piyush Kumar and Sahil Ahmad
    // Helper to reset array
    #define RESET_ARRAY() \
        for (int i = 0; i < n; i++) arr.data[i] = original[i]; \
        arr.size = n

    printf("Original array:\n");
    for (int i = 0; i < n; i++) printf("%d ", original[i]);
    printf("\n\n");

    RESET_ARRAY(); bubbleSort(&arr);
    printf("After Bubble Sort:\n"); printArray(&arr);

    RESET_ARRAY(); selectionSort(&arr);
    printf("After Selection Sort:\n"); printArray(&arr);

    RESET_ARRAY(); insertionSort(&arr);
    printf("After Insertion Sort:\n"); printArray(&arr);

    RESET_ARRAY(); quickSort(&arr);
    printf("After Quick Sort:\n"); printArray(&arr);

    RESET_ARRAY(); mergeSort(&arr);
    printf("After Merge Sort:\n"); printArray(&arr);

    RESET_ARRAY(); countingSort(&arr);
    printf("After Counting Sort:\n"); printArray(&arr);

    RESET_ARRAY(); heapSort(&arr);
    printf("After Heap Sort:\n"); printArray(&arr);

    RESET_ARRAY();
    int unique = sortAndRemoveDuplicates(&arr);
    printf("After sortAndRemoveDuplicates (unique = %d):\n", unique);
    printArray(&arr);

    free(arr.data);
    return 0;
}
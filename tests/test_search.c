#include <stdio.h>
#include <assert.h>
#include "../src/array.c"
#include "../src/search.c"

// Helper function to create and populate an array for testing
Array* createTestArray(int* values, int count, int capacity) {// Created By Sehbaz Singh on 02/10/2025
    Array* arr = createArray(capacity);
    if (!arr) return NULL;
    
    for (int i = 0; i < count; i++) {
        insertArray(arr, i, values[i]);
    }
    return arr;
}

// Test linear search functionality
void testLinearSearch() { //Created By Sanju on 02/10/2025 
    printf("=== Testing Linear Search ===\n");
    
    // Test case 1: Normal array with multiple elements
    printf("Test 1: Linear search in normal array\n");
    int values1[] = {10, 25, 30, 15, 40, 25, 50};
    Array* arr1 = createTestArray(values1, 7, 10);
    
    printf("Array: ");
    traverseArray(arr1);
    
    // Test finding existing elements
    int result = linearSearch(arr1, 30);
    printf("Searching for 30: Found at index %d (expected: 2)\n", result);
    assert(result == 2);
    
    // Test finding first occurrence of duplicate
    result = linearSearch(arr1, 25);
    printf("Searching for 25: Found at index %d (expected: 1 - first occurrence)\n", result);
    assert(result == 1);
    
    // Test element not found
    result = linearSearch(arr1, 99);
    printf("Searching for 99: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    
    freeArray(arr1);
    
    // Test case 2: Empty array
    printf("\nTest 2: Linear search in empty array\n");
    Array* arr2 = createArray(5);
    result = linearSearch(arr2, 10);
    printf("Searching in empty array: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    freeArray(arr2);
    
    // Test case 3: NULL array
    printf("Test 3: Linear search with NULL array\n");
    result = linearSearch(NULL, 10);
    printf("Searching in NULL array: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    
    printf("✓ All Linear Search tests passed!\n\n");
}

// Test binary search functionality
void testBinarySearch() {//Created By Parv Sharma on 02/10/2025
    printf("=== Testing Binary Search ===\n");
    
    // Test case 1: Sorted array
    printf("Test 1: Binary search in sorted array\n");
    int values1[] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
    Array* arr1 = createTestArray(values1, 9, 10);
    
    printf("Sorted Array: ");
    traverseArray(arr1);
    
    // Test finding existing elements
    int result = binarySearch(arr1, 25);
    printf("Searching for 25: Found at index %d (expected: 4)\n", result);
    assert(result == 4);
    
    result = binarySearch(arr1, 5);
    printf("Searching for 5: Found at index %d (expected: 0)\n", result);
    assert(result == 0);
    
    result = binarySearch(arr1, 45);
    printf("Searching for 45: Found at index %d (expected: 8)\n", result);
    assert(result == 8);
    
    // Test element not found
    result = binarySearch(arr1, 22);
    printf("Searching for 22: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    
    result = binarySearch(arr1, 50);
    printf("Searching for 50: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    
    freeArray(arr1);
    
    // Test case 2: Single element array
    printf("\nTest 2: Binary search in single element array\n");
    int values2[] = {42};
    Array* arr2 = createTestArray(values2, 1, 5);
    
    result = binarySearch(arr2, 42);
    printf("Searching for 42 in single element array: Found at index %d (expected: 0)\n", result);
    assert(result == 0);
    
    result = binarySearch(arr2, 10);
    printf("Searching for 10 in single element array: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    
    freeArray(arr2);
    
    // Test case 3: Empty array
    printf("Test 3: Binary search in empty array\n");
    Array* arr3 = createArray(5);
    result = binarySearch(arr3, 10);
    printf("Searching in empty array: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    freeArray(arr3);
    
    // Test case 4: NULL array
    printf("Test 4: Binary search with NULL array\n");
    result = binarySearch(NULL, 10);
    printf("Searching in NULL array: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    
    printf("✓ All Binary Search tests passed!\n\n");
}

// Test findFirstOccurrence functionality
void testFindFirstOccurrence() {// Created By Sanju on 02/10/2025
    printf("=== Testing Find First Occurrence ===\n");
    
    // Test case 1: Array with duplicates
    printf("Test 1: Find first occurrence in array with duplicates\n");
    int values1[] = {10, 20, 30, 20, 40, 20, 50};
    Array* arr1 = createTestArray(values1, 7, 10);
    
    printf("Array: ");
    traverseArray(arr1);
    
    // Test finding first occurrence of duplicate element
    int result = findFirstOccurrence(arr1, 20);
    printf("First occurrence of 20: Found at index %d (expected: 1)\n", result);
    assert(result == 1);
    
    // Test finding unique element
    result = findFirstOccurrence(arr1, 30);
    printf("First occurrence of 30: Found at index %d (expected: 2)\n", result);
    assert(result == 2);
    
    // Test element not found
    result = findFirstOccurrence(arr1, 99);
    printf("First occurrence of 99: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    
    freeArray(arr1);
    
    // Test case 2: All elements same
    printf("\nTest 2: Find first occurrence when all elements are same\n");
    int values2[] = {7, 7, 7, 7, 7};
    Array* arr2 = createTestArray(values2, 5, 8);
    
    result = findFirstOccurrence(arr2, 7);
    printf("First occurrence of 7 in all-same array: Found at index %d (expected: 0)\n", result);
    assert(result == 0);
    
    freeArray(arr2);
    
    // Test case 3: NULL array
    printf("Test 3: Find first occurrence with NULL array\n");
    result = findFirstOccurrence(NULL, 10);
    printf("Searching in NULL array: Found at index %d (expected: -1)\n", result);
    assert(result == -1);
    
    printf("All Find First Occurrence tests passed!\n\n");
}

int main() {
    printf("Starting Search Function Tests\n");
    printf("==============================\n\n");
    
    // Run all test suites
    testLinearSearch();
    testBinarySearch();
    testFindFirstOccurrence();
    
    printf("All tests completed successfully!\n");
    printf("Search module is working correctly.\n");
    
    return 0;
}

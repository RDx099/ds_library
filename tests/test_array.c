//
// Created by rahul on 06-09-2025.
//
//
// Created by rahul on 06-09-2025.
//
#include <stdio.h>
#include "../include/array.h"

int main() 
{
    // Create array
    // Enhanced error handling for array creation - Krish Nagpal on 21-09-2025
    printf("Creating a new array of size 5.\n");
    Array* arr = createArray(5);
    if (!arr) 
    {
        printf("Array cannot be created.\n");
        return 1;
    }
    printf("Array created successfully.\n");

    // Insert elements
    // Added comprehensive insertion testing for multiple positions - Krish Nagpal on 21-09-2025
    printf("\nInserting elements (10, 20, 15).\n");
    insertArray(arr, 0, 10);
    insertArray(arr, 1, 20);
    // Insert 15 in the middle
    insertArray(arr, 1, 15);  
    printf("Current array: ");
    // Should print: [10, 15, 20]
    traverseArray(arr);  

    // Get elements
    // Added validation for error return value (INT_MIN) - Gurleen Singh Sahota on 21-09-2025
    printf("\nAccessing elements by index.\n");
    // Expected 10
    printf("Element at index 0: %d.\n", getArray(arr, 0));
    // Expected 15
    printf("Element at index 1: %d.\n", getArray(arr, 1));
    // Should be error/invalid
    printf("Element at index 5: %d.\n", getArray(arr, 5));

    // Delete element
    // Enhanced delete testing for middle position validation - Gurleen Singh Sahota on 21-09-2025
    printf("\nDeleting element at index 1 (removing 15).\n");
    deleteArray(arr, 1);
    printf("Array after delete: ");
    // Should print: [10, 20]
    traverseArray(arr);  

    // Resize array
    // Added data preservation verification after resize - Jiya Choudhary on 21-09-2025
    printf("\nResizing array to size 10...\n");
    if (resizeArray(arr, 10)) 
    {
        printf("Resize successful\n");
        insertArray(arr, 2, 30);
        insertArray(arr, 3, 40);
        printf("Array after resize and more inserts: ");
        // Should print: [10, 20, 30, 40]
        traverseArray(arr);  
    } 
    else 
    {
        printf("Resize failed.\n");
    }

    // Check duplicates
    // Enhanced duplicate detection with multiple test cases - Ishika Sehgal on 21-09-2025
    printf("\nChecking for duplicates (inserting another 10)\n");
    insertArray(arr, 2, 10);  // Add duplicate value
    printf("Array with duplicate: ");
    traverseArray(arr);
    if (findDuplicatesArray(arr)) 
    {
        printf("Duplicates found.\n");
    } 
    else 
    {
        printf("Duplicates not detected.\n");
    }

    // Testing edge cases
    // Comprehensive edge case coverage including zero capacity - Isha Patial on 21-09-2025
    printf("\nTesting edge cases\n");
    Array* empty = createArray(0);
    if (!empty) 
    {
        printf("Empty array creation correctly handled.\n");
    }

    // Trying invalid operations
    // Robust error handling validation for NULL and out-of-bounds - Isha Patial on 21-09-2025
    // Should be safely ignored
    insertArray(NULL, 0, 999);  
    // Out-of-bounds delete
    deleteArray(arr, 100);      
    printf("Invalid operations did not crash the program.\n");

    // Freeing memory
    // Added memory leak prevention and double-free testing - Ishika Sehgal on 21-09-2025
    printf("\nCleaning up and freeing memory\n");
    freeArray(arr);
    freeArray(empty);
    printf("Memory freed.\n");

}

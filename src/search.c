//
// Created by rahul on 06-09-2025.
//
//
// Created by rahul on 06-09-2025.
//

#include "../include/search.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Performs Linear Search on an Array to find a value
// Parameters: arr (Array pointer), value (data to find)
// Returns: Index of the first occurrence of value, or -1 if not found

int linearSearch(Array* arr, int value) {//Created By Sashank Rana on 01/10/2025 
    if (arr == NULL) {
        return -1;
    }
    
    int size = getSizeArray(arr);
    if (size <= 0) {
        return -1;
    }
    
    // Iterate through all elements in the array
    for (int i = 0; i < size; i++) {
        if (getArray(arr, i) == value) {
            return i; // Return index of first occurrence
        }
    }
    
    return -1; // Value not found
}

// Performs Binary Search on a sorted Array to find a value
// Parameters: arr (Array pointer, must be sorted), value (data to find)
// Returns: Index of the value, or -1 if not found
// Precondition: Array is sorted in ascending order

int binarySearch(Array* arr, int value) {// Created By Sehbaz Singh on 01/10/2025
    if (arr == NULL) {
        return -1;
    }
    
    int size = getSizeArray(arr);
    if (size <= 0) {
        return -1;
    }
    
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow
        int midValue = getArray(arr, mid);
        
        if (midValue == value) {
            return mid; // Value found at mid index
        } else if (midValue < value) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    
    return -1; // Value not found
}

// Placement problem: Finds the first occurrence of a value in an Array
// Parameters: arr (Array pointer), value (data to find)
// Returns: Index of the first occurrence, or -1 if not found
int findFirstOccurrence(Array* arr, int value) {// Created By Sahil Bhandari on 01/10/2025
    if (arr == NULL) {
        return -1;
    }
    
    int size = getSizeArray(arr);
    if (size <= 0) {
        return -1;
    }
    
    // This is essentially the same as linear search since we need
    // the FIRST occurrence. Linear search naturally finds the first one.
    for (int i = 0; i < size; i++) {
        if (getArray(arr, i) == value) {
            return i; // Return index of first occurrence
        }
    }
    
    return -1; // Value not found
}

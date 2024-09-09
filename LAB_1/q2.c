#include <stdio.h>

// Function to sort the array using Bubble Sort
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to perform Binary Search
int binarySearch(int array[], int size, int key) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if key is present at mid
        if (array[mid] == key) {
            return mid; // Element found at index mid
        }
        
        // If key is greater, ignore left half
        if (array[mid] < key) {
            left = mid + 1;
        } else {
            // If key is smaller, ignore right half
            right = mid - 1;
        }
    }
    
    return -1; // Element is not present in the array
}

int main() {
    int n, key;
    
    // Input: number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int array[n];
    
    // Input: elements of the array
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Input: element to search for
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    // Sort the array before performing binary search
    bubbleSort(array, n);
    
    // Perform binary search
    int result = binarySearch(array, n, key);
    
    // Output: result of search
    if (result != -1) {
        printf("Element %d found at index %d (after sorting).\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    
    return 0;
}

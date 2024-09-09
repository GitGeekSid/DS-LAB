#include <stdio.h>

// Function for Binary Search (recursive)
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;  // Element not found

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;  // Element found
    else if (arr[mid] > target)
        return binarySearch(arr, low, mid - 1, target);  // Search left half
    else
        return binarySearch(arr, mid + 1, high, target);  // Search right half
}

// Function for Selection Sort (recursive)
void selectionSort(int arr[], int n, int index) {
    if (index == n)  // Base case: all elements sorted
        return;

    int minIndex = index;

    // Find the minimum element in the remaining unsorted array
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    // Swap the found minimum element with the first element
    if (minIndex != index) {
        int temp = arr[minIndex];
        arr[minIndex] = arr[index];
        arr[index] = temp;
    }

    // Recursive call to sort the remaining elements
    selectionSort(arr, n, index + 1);
}

// Function to multiply two numbers using repeated addition (recursive)
int multiply(int a, int b) {
    if (b == 0)
        return 0;
    else if (b > 0)
        return a + multiply(a, b - 1);
    else
        return -multiply(a, -b);  // Handle negative b
}

// Function to display an array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, target, result, a, b;

    // Input array size and elements for binary search and selection sort
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Binary Search
    printf("Enter the element to search using Binary Search: ");
    scanf("%d", &target);
    result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index: %d\n", result);

    // Selection Sort
    printf("Array before sorting: ");
    displayArray(arr, n);
    selectionSort(arr, n, 0);
    printf("Array after Selection Sort: ");
    displayArray(arr, n);

    // Multiplication using repeated addition
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &a, &b);
    printf("Product of %d and %d is: %d\n", a, b, multiply(a, b));

    return 0;
}

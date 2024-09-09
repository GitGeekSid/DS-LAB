#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // Traverse through all elements in the array
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;

    // Input the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  // Declare an array of size n

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the array before sorting
    printf("Array before sorting: ");
    displayArray(arr, n);

    // Perform selection sort
    selectionSort(arr, n);

    // Display the array after sorting
    printf("Array after sorting: ");
    displayArray(arr, n);

    return 0;
}

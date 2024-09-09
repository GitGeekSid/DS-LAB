#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;

    // Traverse from arr[1] to arr[n-1]
    for (i = 1; i < n; i++) {
        key = arr[i];  // Current element to be inserted
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than the key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Insert the key into its correct position
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

    // Perform insertion sort
    insertionSort(arr, n);

    // Display the array after sorting
    printf("Array after sorting: ");
    displayArray(arr, n);

    return 0;
}

#include <stdio.h>

// Function to perform Bubble Sort
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

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input: number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n];

    // Input: elements of the array
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Sort the array using Bubble Sort
    bubbleSort(array, n);

    // Output: sorted array
    printf("Sorted array: ");
    printArray(array, n);

    return 0;
}

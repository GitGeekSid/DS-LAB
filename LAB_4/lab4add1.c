#include <stdio.h>

// Define a structure to represent the elements of the sparse matrix
struct Element {
    int row;
    int col;
    int value;
};

// Function to read a sparse matrix
void readSparseMatrix(struct Element sparse[], int *n) {
    int totalElements;

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &totalElements);
    *n = totalElements;

    printf("Enter row, column, and value for each element:\n");
    for (int i = 0; i < totalElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d%d%d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Element sparse[], int n) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

// Function to find the transpose of a sparse matrix
void transposeSparseMatrix(struct Element sparse[], struct Element transpose[], int n) {
    for (int i = 0; i < n; i++) {
        transpose[i].row = sparse[i].col;  // Swap row and column
        transpose[i].col = sparse[i].row;
        transpose[i].value = sparse[i].value;
    }
}

// Function to sort the transpose matrix by row and then by column
void sortSparseMatrix(struct Element sparse[], int n) {
    struct Element temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sparse[i].row > sparse[j].row || (sparse[i].row == sparse[j].row && sparse[i].col > sparse[j].col)) {
                // Swap elements
                temp = sparse[i];
                sparse[i] = sparse[j];
                sparse[j] = temp;
            }
        }
    }
}

int main() {
    int n;  // Number of non-zero elements
    struct Element sparse[100], transpose[100];

    // Read the sparse matrix
    readSparseMatrix(sparse, &n);

    printf("\nOriginal Sparse Matrix:\n");
    displaySparseMatrix(sparse, n);

    // Find the transpose of the sparse matrix
    transposeSparseMatrix(sparse, transpose, n);

    // Sort the transpose matrix
    sortSparseMatrix(transpose, n);

    printf("\nTranspose of Sparse Matrix:\n");
    displaySparseMatrix(transpose, n);

    return 0;
}

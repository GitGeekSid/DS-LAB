#include <stdio.h>

// Structure to represent a sparse matrix entry (triplet: row, col, value)
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to read a sparse matrix
void readSparseMatrix(struct SparseMatrix matrix[], int numElements) {
    printf("Enter the elements (row, column, value):\n");
    for (int i = 0; i < numElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(struct SparseMatrix matrix[], int numElements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

// Function to perform fast transpose of a sparse matrix
void fastTranspose(struct SparseMatrix original[], struct SparseMatrix transposed[], int numElements, int numRows, int numCols) {
    int rowTerms[numCols]; // Array to store count of elements in each column
    int startingPos[numCols]; // Array to store starting position of elements in transposed matrix

    // Initialize rowTerms to 0
    for (int i = 0; i < numCols; i++) {
        rowTerms[i] = 0;
    }

    // Count the number of elements in each column of the original matrix
    for (int i = 0; i < numElements; i++) {
        rowTerms[original[i].col]++;
    }

    // Compute starting position of each column in transposed matrix
    startingPos[0] = 0;
    for (int i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    // Place elements in the transposed matrix
    for (int i = 0; i < numElements; i++) {
        int pos = startingPos[original[i].col]++;
        transposed[pos].row = original[i].col;
        transposed[pos].col = original[i].row;
        transposed[pos].value = original[i].value;
    }
}

int main() {
    int numRows, numCols, numElements;

    // Input number of rows, columns, and non-zero elements in the sparse matrix
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &numRows, &numCols);
    
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numElements);

    struct SparseMatrix original[numElements];  // Array to store original matrix
    struct SparseMatrix transposed[numElements];  // Array to store transposed matrix

    // Read original sparse matrix
    readSparseMatrix(original, numElements);

    // Display original sparse matrix
    printf("\nOriginal Sparse Matrix:\n");
    displaySparseMatrix(original, numElements);

    // Perform fast transpose
    fastTranspose(original, transposed, numElements, numRows, numCols);

    // Display transposed sparse matrix
    printf("\nTransposed Sparse Matrix (Fast Transpose):\n");
    displaySparseMatrix(transposed, numElements);

    return 0;
}

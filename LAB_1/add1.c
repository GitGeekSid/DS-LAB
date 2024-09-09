#include <stdio.h>

#define MAX 100  // Define the maximum size of the matrix

// Function to read a matrix from the user
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to create matrix C such that C(i, j) = max(A(i, j), B(i, j))
void createMaxMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = (A[i][j] > B[i][j]) ? A[i][j] : B[i][j];  // Find maximum of A(i, j) and B(i, j)
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rows, cols;

    // Input the dimensions of the matrices
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Read matrix A
    printf("\nEnter elements of matrix A:\n");
    readMatrix(A, rows, cols);

    // Read matrix B
    printf("\nEnter elements of matrix B:\n");
    readMatrix(B, rows, cols);

    // Create matrix C (max(A, B))
    createMaxMatrix(A, B, C, rows, cols);

    // Display matrix A
    printf("\nMatrix A:\n");
    displayMatrix(A, rows, cols);

    // Display matrix B
    printf("\nMatrix B:\n");
    displayMatrix(B, rows, cols);

    // Display matrix C (max(A, B))
    printf("\nMatrix C (Max of A and B):\n");
    displayMatrix(C, rows, cols);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Function to multiply two matrices
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to add two matrices
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to check if a square matrix is a magic square
bool isMagicSquare(int matrix[MAX][MAX], int n) {
    int sum = 0, diag1 = 0, diag2 = 0;

    // Sum of the first row
    for (int i = 0; i < n; i++) {
        sum += matrix[0][i];
    }

    // Check sum of rows
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sum) return false;
    }

    // Check sum of columns
    for (int i = 0; i < n; i++) {
        int colSum = 0;
        for (int j = 0; j < n; j++) {
            colSum += matrix[j][i];
        }
        if (colSum != sum) return false;
    }

    // Check diagonals
    for (int i = 0; i < n; i++) {
        diag1 += matrix[i][i];
        diag2 += matrix[i][n - i - 1];
    }

    return (diag1 == sum && diag2 == sum);
}

// Function to print matrix
void printMatrix(int matrix[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2, n;
    
    // Reading first matrix A
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Reading second matrix B
    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Multiply two matrices
    if (c1 == r2) {
        multiplyMatrices(A, B, result, r1, c1, r2, c2);
        printf("\nMultiplication of matrices A and B:\n");
        printMatrix(result, r1, c2);
    } else {
        printf("\nMatrix multiplication not possible.\n");
    }

    // Add two matrices
    if (r1 == r2 && c1 == c2) {
        addMatrices(A, B, result, r1, c1);
        printf("\nAddition of matrices A and B:\n");
        printMatrix(result, r1, c1);
    } else {
        printf("\nMatrix addition not possible.\n");
    }

    // Check for magic square
    printf("Enter the size of the square matrix (for magic square check): ");
    scanf("%d", &n);
    int square[MAX][MAX];
    printf("Enter the elements of the square matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &square[i][j]);
        }
    }

    if (isMagicSquare(square, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is not a magic square.\n");
    }

    return 0;
}

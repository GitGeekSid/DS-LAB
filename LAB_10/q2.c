#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to create a binary tree
struct Node* createBinaryTree(int* arr, int index, int size) {
    // Base case: if the index is out of bounds of the array
    if (index >= size) {
        return NULL;
    }

    // Create the current node
    struct Node* root = createNode(arr[index]);

    // Recursively create the left and right subtrees
    root->left = createBinaryTree(arr, 2 * index + 1, size);  // Left child
    root->right = createBinaryTree(arr, 2 * index + 2, size); // Right child

    return root;
}

// Recursive function to print the binary tree in-order
void printInOrder(struct Node* root) {
    if (root != NULL) {
        printInOrder(root->left);         // Visit left subtree
        printf("%d ", root->data);        // Visit node
        printInOrder(root->right);        // Visit right subtree
    }
}

// Main function
int main() {
    // Example array to create a binary tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create the binary tree
    struct Node* root = createBinaryTree(arr, 0, size);

    // Print the binary tree in-order
    printf("In-order traversal of the binary tree: ");
    printInOrder(root);
    printf("\n");

    // Free the allocated memory (not shown here for simplicity)
    // You should implement a function to free the tree nodes to avoid memory leaks

    return 0;
}
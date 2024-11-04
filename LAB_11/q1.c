#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
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

// Function to insert a new element into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for an element in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete an element from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for an element
    int searchValue = 40;
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Element %d found in the BST.\n", searchValue);
    } else {
        printf("Element %d not found in the BST.\n", searchValue);
    }

    // Delete an element
    int deleteValue = 20;
    root = deleteNode(root, deleteValue);
    printf("In-order traversal after deleting %d: ", deleteValue);
    inOrderTraversal(root);
    printf("\n");

    // Delete another element
    deleteValue = 30;
    root = deleteNode(root, deleteValue);
    printf("In-order traversal after deleting %d: ", deleteValue);
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
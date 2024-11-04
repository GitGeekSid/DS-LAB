#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for iterative traversals
struct Stack {
    struct Node* node;
    struct Stack* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Push a node onto the stack
void push(struct Stack** stack, struct Node* node) {
    struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
    newStackNode->node = node;
    newStackNode->next = *stack;
    *stack = newStackNode;
}

// Pop a node from the stack
struct Node* pop(struct Stack** stack) {
    if (*stack == NULL) return NULL;
    struct Stack* temp = *stack;
    struct Node* node = temp->node;
    *stack = (*stack)->next;
    free(temp);
    return node;
}

// Check if stack is empty
bool isEmpty(struct Stack* stack) {
    return stack == NULL;
}

// i) Iterative Inorder Traversal
void inorderTraversal(struct Node* root) {
    struct Stack* stack = NULL;
    struct Node* curr = root;

    while (curr != NULL || !isEmpty(stack)) {
        while (curr != NULL) {
            push(&stack, curr);
            curr = curr->left;
        }
        curr = pop(&stack);
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

// ii) Iterative Postorder Traversal
void postorderTraversal(struct Node* root) {
    struct Stack* stack1 = NULL;
    struct Stack* stack2 = NULL;
    if (root == NULL) return;

    push(&stack1, root);
    while (!isEmpty(stack1)) {
        struct Node* node = pop(&stack1);
        push(&stack2, node);

        if (node->left) push(&stack1, node->left);
        if (node->right) push(&stack1, node->right);
    }
    while (!isEmpty(stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
    printf("\n");
}

// iii) Iterative Preorder Traversal
void preorderTraversal(struct Node* root) {
    struct Stack* stack = NULL;
    if (root == NULL) return;

    push(&stack, root);
    while (!isEmpty(stack)) {
        struct Node* node = pop(&stack);
        printf("%d ", node->data);

        if (node->right) push(&stack, node->right);
        if (node->left) push(&stack, node->left);
    }
    printf("\n");
}

// iv) Print the parent of a given element
void printParent(struct Node* root, int element) {
    if (root == NULL || root->data == element) return;

    struct Stack* stack = NULL;
    struct Node* parent = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(&stack);

        if ((node->left && node->left->data == element) || 
            (node->right && node->right->data == element)) {
            printf("Parent of %d: %d\n", element, node->data);
            return;
        }
        if (node->right) push(&stack, node->right);
        if (node->left) push(&stack, node->left);
    }
    printf("Element not found in tree\n");
}

// v) Print the depth of the tree
int treeDepth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// vi) Print the ancestors of a given element
bool printAncestors(struct Node* root, int element) {
    if (root == NULL) return false;

    if (root->data == element) return true;

    if (printAncestors(root->left, element) || printAncestors(root->right, element)) {
        printf("%d ", root->data);
        return true;
    }
    return false;
}

// vii) Count the number of leaf nodes in a binary tree
int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Main function to demonstrate the operations
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");
    inorderTraversal(root);

    printf("Postorder Traversal: ");
    postorderTraversal(root);

    printf("Preorder Traversal: ");
    preorderTraversal(root);

    printf("Parent of 5: ");
    printParent(root, 5);

    printf("Depth of the tree: %d\n", treeDepth(root));

    printf("Ancestors of 7: ");
    if (!printAncestors(root, 7)) {
        printf("Element not found in tree");
    }
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeaves(root));

    return 0;
}

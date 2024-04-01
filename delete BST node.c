#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform inorder traversal of the BST
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Function to find the minimum value node in a BST
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with a given key from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in the left subtree
    if (key < root->val)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in the right subtree
    else if (key > root->val)
        root->right = deleteNode(root->right, key);

    // If the key is same as the root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree) and copy its value to this node. Then delete the successor
        struct TreeNode* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main() {
    // Construct the BST
    struct TreeNode* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    // Delete node with value 30
    root = deleteNode(root, 30);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

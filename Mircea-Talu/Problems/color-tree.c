#include <stdio.h>
#include <stdlib.h>

int counter = 1;

struct TreeNode {
    int data;
    struct TreeNode *parent;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insertNode(struct TreeNode *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        struct TreeNode *newNode = insertNode(root->left, data);
        root->left = newNode;
        newNode->parent = root;
    } else if (data > root->data) {
        struct TreeNode *newNode = insertNode(root->right, data);
        root->right = newNode;
        newNode->parent = root;
    }

    return root;
}

void inorderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        if(root->parent != NULL) {
            if(root->data != root->parent->data) {
                counter++;
            }
        }
        
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct TreeNode *root = NULL;
    root = insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 1);
    insertNode(root, 1);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 1);

    inorderTraversal(root);

    printf("\nNumber of colors: %d", counter);

    return 0;
}

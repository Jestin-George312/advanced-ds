#include <stdio.h>
#include <stdlib.h>
struct node {
struct node *left;
struct node *right;
int data;
};
struct node *root;
// Function to create a new node
struct node* newNode(int value) {
struct node *newnode = malloc(sizeof(struct node));
newnode->data = value;
newnode->left = NULL;
newnode->right = NULL;
return newnode;
}
// Function to insert a node in the binary search tree
struct node* insert(struct node* root, int value) {
if (root == NULL) {
return newNode(value);
} else if (value == root->data) {
printf("Same data can't be stored\n");
} else if (value > root->data) {
root->right = insert(root->right, value);
} else if (value < root->data) {
root->left = insert(root->left, value);
}
return root; // Ensure the updated root is returned
}
// Inorder traversal (left-root-right)
void inorderTraversal(struct node* root) {
if (root == NULL) return;
inorderTraversal(root->left);
printf("%d ->", root->data);
inorderTraversal(root->right);
}
// Preorder traversal (root-left-right)
void preorderTraversal(struct node* root) {
if (root == NULL) return;
printf("%d ->", root->data);
preorderTraversal(root->left);
preorderTraversal(root->right);
}
// Postorder traversal (left-right-root)
void postorderTraversal(struct node* root) {
if (root == NULL) return;
postorderTraversal(root->left);
postorderTraversal(root->right);
printf("%d ->", root->data);
}
// Function to search for a value in the tree
struct node* search(struct node* root, int key) {
if (root == NULL) {
printf("\nNot FOUND!\n");
return NULL;
} else if (root->data == key) {
printf("\nFOUND! Node data: %d\n", root->data);
return root;
} else if (root->data < key) {
return search(root->right, key);
} else {
return search(root->left, key);
}
}
// Function to find the minimum value node in a tree
struct node* minValueNode(struct node* node) {
struct node* current = node;
while (current && current->left != NULL) {
current = current->left;
}
return current;
}

// Function to delete a node in the tree
struct node* deleteNode(struct node* root, int key) {
if (root == NULL) {
return root;
}
// Traverse the tree to find the node to delete
if (key < root->data) {
root->left = deleteNode(root->left, key);
} else if (key > root->data) {
root->right = deleteNode(root->right, key);
} else {
// Node with one or no children
if (root->left == NULL) {
struct node* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct node* temp = root->left;
free(root);
return temp;
}
// Node with two children: Get the inorder successor
struct node* temp = minValueNode(root->right);
// Copy the inorder successor's content to this node
root->data = temp->data;
// Delete the inorder successor
root->right = deleteNode(root->right, temp->data);
}
return root;
}
int main() {
int opt;
int value, searchv, key;
do {
printf("\n1) Create Root Node \n2) Insert Node\n3) Search\n");
printf("4) Inorder Traversal \n5) Preorder Traversal \n6) Postorder Traversal \n7) Delete \n8) Quit \n");
printf("Choose Option :: ");
scanf("%d", &opt);
switch (opt) {
case 1:
printf("\nEnter a number: ");
scanf("%d", &value);
root = newNode(value);
break;
case 2:
printf("\nEnter a number: ");
scanf("%d", &value);
root = insert(root, value); // Make sure root is updated
// After insertion, print the tree to verify it's correct
printf("Inorder Traversal after insertion: ");
inorderTraversal(root);
printf("\n");
break;
case 3:
printf("\nEnter a number: ");
scanf("%d", &searchv);
struct node* foundNode = search(root, searchv);
if (!foundNode) {
printf("\nNode with value %d not found.\n", searchv);
}
break;
case 4:
printf("\nInorder Traversal: ");
inorderTraversal(root);
printf("\n");
break;
case 5:
printf("\nPreorder Traversal: ");
preorderTraversal(root);
printf("\n");
break;
case 6:
printf("\nPostorder Traversal: ");
postorderTraversal(root);
printf("\n");

break;
case 7:
printf("\nEnter a number to be deleted: ");
scanf("%d", &key);
root = deleteNode(root, key); // Ensure the root is updated
break;
case 8:
printf("Exiting program...\n");
break;
default:
printf("Invalid option!\n");
}
} while (opt != 8);
return 0;
}

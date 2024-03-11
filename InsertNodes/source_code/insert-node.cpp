#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct node *PtrToNode;

struct node
{
    int data;
    PtrToNode LeftPtr;
    PtrToNode RightPtr;
};

// Function to create node
struct node* CreateNode(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->LeftPtr = NULL;
    newNode->RightPtr = NULL;
    printf("\n Node created with value %d \n", newNode->data);
    return newNode;
}

void preorderTraversal(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print the current node's value
        preorderTraversal(root->LeftPtr);
        preorderTraversal(root->RightPtr);
    }
}

void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->LeftPtr);
        printf("%d ", root->data); // Print the current node's value
        inorderTraversal(root->RightPtr);
    }
}

void postorderTraversal(struct node* root) {
    if (root != NULL) {
        postorderTraversal(root->LeftPtr);
        postorderTraversal(root->RightPtr);
        printf("%d ", root->data); // Print the current node's value
    }
}

struct node* insertKey (struct node* root, int key){
    if (root == NULL)
        return CreateNode(key);
        // Otherwise, recur down the tree
    if (key < root->data)
        root->LeftPtr = insertKey(root->LeftPtr, key);
    else if (key > root->data)
        root->RightPtr = insertKey(root->RightPtr, key);
 
    // Return the (unchanged) node pointer
    return root;
        
}


int main () {
    // This is the tree we want to build
    //         25
    //         /\
    //     10      34
    //     /
    // 5
    // expect pre-order traversal to be: 25, 10, 5, 34.

    struct node* root = CreateNode(25);
    root->LeftPtr = CreateNode(10);
    root->LeftPtr->LeftPtr = CreateNode(5);
    root->RightPtr = CreateNode(34);

    printf("Verify tree with pre-order traversal: \n");
    preorderTraversal(root);

    printf("\n");
    printf("Verify tree with in-order traversal: \n");
    inorderTraversal(root);

    printf("\n");
    printf("Verify tree with post-order traversal: \n");
    postorderTraversal(root);

    // This is the new tree after insert 6
    //         25
    //         /\
    //     10      34
    //     /
    //    5
    //     \
    //      6
    // expect pre-order traversal: 25 10 5 6 34
    // expect in-order traversal: 6 5 10 25 35
    // expect post-order traversal: 6 5 10 34 25

    int newKey = 6;
    insertKey(root, newKey);
    // verify new tree:
    printf("\n");
    printf("New key inserted: %d \n", newKey);
    printf("Verify new tree with pre-order traversal: \n");
    preorderTraversal(root);
    printf("\n");
    printf("Verify new tree with in-order traversal: \n");
    inorderTraversal(root);
    printf("\n");
    printf("Verify new tree with post-order traversal: \n");
    postorderTraversal(root);



    return 0;
}
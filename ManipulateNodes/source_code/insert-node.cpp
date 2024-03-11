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

struct node* insertKey (){

};


int main () {
    // This is the tree we want to build
    //         25
    //         /\
    //     10      34
    //     /
    // 20
    // expect pre-order traversal to be: 25, 10, 20, 34.

    struct node* root = CreateNode(25);
    root->LeftPtr = CreateNode(10);
    root->LeftPtr->LeftPtr = CreateNode(20);
    root->RightPtr = CreateNode(34);

    printf("Verify tree with pre-order traversal: \n");
    preorderTraversal(root);

    printf("\n");
    printf("Verify tree with in-order traversal: \n");
    inorderTraversal(root);

    printf("\n");
    printf("Verify tree with post-order traversal: \n");
    postorderTraversal(root);

    return 0;
}
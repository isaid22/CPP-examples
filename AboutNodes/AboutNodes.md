## Nodes and tree as a data structure
Nodes are fundamental unit of data elements in a tree data structure. A node consists of value and one or more pointers for pointing
to another node. Below is an example of a node for binary tree. It is for binary tree because this node has maximum two pointers.

```
int node_val;
node *LeftPtr;
node *rightPtr;
```

To implement it:

```
typedef struct TreeNode *PtrToNode;
struct TreeNode {
    ElementType Element;
    PtrToNode FirstChildPtr;
    PtrToNode NextSiblingPtr;
}
```

Notice that we use `typedef` to simplify declaration of the node's pointers. 

### Create a new node for binary tree:

Here is the code to implement a binary tree's node:

```
typedef struct node *PtrToNode;
struct node
{
    int data;
    PtrToNode LeftPtr;
    PtrToNode RightPtr;
}
```

Now to create a new node from the declaration above, we want a function that takes the value as the data, and return a pointer 
to the new node created with that value. Therefore, we want this function to return a pointer to the `struct`:
```
struct node* create(value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->LeftPtr = NULL;
    newNode->RightPtr = NULL;;

    return newNode;
}
```
In this function, the first thing we need to do is to allocate memory for this node. We use `malloc` to accomplish this. Once this is done, it is assigned to a pointer `newNode`. After this is done, we then make assignment to the elements in this node. The new node created will have left and right pointers, pointeing at NULL.

### Implement a tree
Now we know how to define a node, lets us see how to implement a tree. Here is a simple tree:
```
        1
        /\
    10      34
    /
20
```
To implement this pattern, we will use what we learned about the way to declare the node. First we need to define a root node with value 1:
```
struct node* root = create(1);
```
Then define root node's left child node:
```
root->LeftPtr = create(10);
```
Then follow by the next left child in next level:
```
root->LeftPtr->Leftpr = create(20);
```
Don't forget also we have a right child node for the root:
```
root->RightPtr = create(34);
```

### Verify tree implementation
One way to verify the implementation of a tree is through traversal. There are many different traversal patterns. In this example, we will use In-Order Traversal, where we start with leftmost leaf, going up to its parent, from there, if there is another leaf, go down to that leaf. If not, from the parent, go up another level to the grandparent, and if there is another leaf, go down again. If not, go up to grand-granparent. Eventually you will end up at root node. At this point, if root has another leaf, then go down to that leaf again. 

Given the description for pre-order traversal, this is the expected output of our tree, as shown by the data held in each node:

```
Verify tree with pre-order traversal 
1 10 20 34
```

To try this example, use source code shown in [here](./source_code/Nodes.cpp)

In the directory of the source code, compile the code:

```
g++ -o nodes Nodes.cpp -Wall -std=c++17
```

and run it:
```
./node
```

#### Pre-Order Traversal
To implement this traversal:
```
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print the current node's value
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
```
In a pre-order traversal, the printf statement is placed at the beginning of the function, before the recursive calls to the left and right subtrees. This results in printing the current node's value before visiting its children.

#### Post-Order Traversal
To implement this traversal:
```
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        printf("%d ", root->data); // Print the current node's value
    }
}
```
In a post-order traversal, the printf statement is placed after the recursive calls to the left and right subtrees. This means that the current node's value is printed after visiting its children.

#### In-Order Traversal
To implement this traversal:
```
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data); // Print the current node's value
        inorderTraversal(root->right);
    }
}
```
In an in-order traversal of a binary tree, the printf statement is placed between the recursive calls to the left and right subtrees. This ensures that the values are printed in ascending order because the left subtree contains values smaller than the current node, and the right subtree contains values larger than the current node.



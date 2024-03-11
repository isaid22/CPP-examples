## Insert a new node
Inserting a new node into an existing binary search tree reqiures scanning through all the nodes to find the proper node as the new parent. This has O(N) search time. Without considering duplicate node values, the general rule is:

1. Compare new node value with the root. If less than the root value, then go down left leaf, If greater than the root value, go down right leaf.
2. Continue with next node. Repeat the same step for comparison until reaching the leaf node.
3. Create a new node with the leaf node as parent.

## Example

Assume a binary search tree is already set:

```
             25
             /\
         10      34
         /
        5
```

Now we want to insert a new node with value 6.
We expect the new tree to be:

```
             25
             /\
         10      34
         /
        5
         \
          6
```
The new tree may be verified with the tree traversal results:

```
New key inserted: 6 
Verify new tree with pre-order traversal: 
25 10 5 6 34 
Verify new tree with in-order traversal: 
5 6 10 25 34 
Verify new tree with post-order traversal: 
6 5 10 34 25
```

The soure code example is [here](./source_code/insert-node.cpp)

## Explanation
We add a new function to provide the insert capability:

```
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
```

This function takes the tree and the known value denoted as `key` that we want to insert. We leverage recursion to achieve the base case, which is when the function call ran out of node (because we just traversed the leaf), and therefore the base considion `root == NULL` is met, and we go ahead and use `CreateNode` to create the new node with the new valule.

As for the which size of should this new node belong, left or right leaf? This is done by comparing value `key` with `root-data`, just as rule 1. 

To try the example code, compile it:

`g++ -o insert-node insert-node.cpp -Wall -std=c++17`

Then run it:

`./insert-code`

and expect results:

```
 Node created with value 25 

 Node created with value 10 

 Node created with value 5 

 Node created with value 34 
Verify tree with pre-order traversal: 
25 10 5 34 
Verify tree with in-order traversal: 
5 10 25 34 
Verify tree with post-order traversal: 
5 10 34 25 
 Node created with value 6 

New key inserted: 6 
Verify new tree with pre-order traversal: 
25 10 5 6 34 
Verify new tree with in-order traversal: 
5 6 10 25 34 
Verify new tree with post-order traversal: 
6 5 10 34 25 
```
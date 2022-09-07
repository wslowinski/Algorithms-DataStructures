# Binary Search Tree
Binary Search Tree (BST) is a rooted binary tree data structure with the key 
of each internal node being greater than all the keys in the respective node's 
left subtree and less than the ones in its right subtree. This directory 
contains Binary Search Tree implementation.

## Interface
```cpp
class BinarySearchTree {
    BinarySearchTree();                  // Constructs the BST
    void insert(const int& x);           // Inserts element
    int size();                          // Returns the number of elements
    int minimum();                       // Returns minimum value
    int maximum();                       // Returns maximum value
    int depth();                         // Returns tree depth;
    int* search(const int& x);           // Iteration version of tree search
    int* searchRecursive(const int& x);  // Recursive version of tree search
    void inorder();                      // In-order, LNR
    void preorder();                     // Pre-order, NLR
    void postorder();                    // Post-order, LRN
};
```

## Content
* ```BinaryTree.h```,  ```BinaryTree.cpp``` - BST Implementation;


## Technologies
Project is created with ```C++17```.

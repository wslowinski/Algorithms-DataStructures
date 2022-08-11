#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

class Node {
public:
    int key;
    Node *left, *right;
    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(const int& x) {
        key = x;
    }
};

class BinarySearchTree {
public:
    int counter;
    Node* root;

public:
    BinarySearchTree();
    ~BinarySearchTree() = default;
    int minimum(Node* w);
    int maximum(Node* w);
    int depth(Node* w);
    void visit(Node* w);
    int* search(Node* w, const int& x);
    int* searchRecursive(Node* w, const int& x);
    void inorder(Node* w);
    void preorder(Node* w);
    void postorder(Node* w);

    void insert(const int& x);
    int size();
    int minimum();
    int maximum();
    int depth();
    int* search(const int& x);
    int* searchRecursive(const int& x);
    void inorder();
    void preorder();
    void postorder();
};

#endif

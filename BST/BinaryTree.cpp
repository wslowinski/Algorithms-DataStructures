#include "BinaryTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
    counter = 0;
}

void BinarySearchTree::visit(Node* w) {
    std::cout << w->key << std::endl;
}

void BinarySearchTree::insert(const int& x) {
    Node* w = root;
    Node* prev = nullptr;
    while (w != nullptr) {
        prev = w;
        if (w->key <= x) {
            w = w->right;
        }
        else {
            w = w->left;
        }
    }
    if (root == nullptr) {
        root = new Node(x);
    }
    else if (prev->key <= x) {
        prev->right = new Node(x);
    }
    else {
        prev->left = new Node(x);
    }
    counter++;
}

int BinarySearchTree::size() {
    return counter;
}

int BinarySearchTree::minimum(Node* w) {
    if (w == nullptr) {
        return -1;
    }
    else if (w->left == nullptr) {
        return w->key;
    }
    return minimum(w->left);
}

int BinarySearchTree::minimum() {
    return minimum(root);
}

int BinarySearchTree::maximum(Node* w) {
    if (w == nullptr) {
        return -1;
    }
    else if (w->right == nullptr) {
        return w->key;
    }
    return maximum(w->right);
}

int BinarySearchTree::maximum() {
    return maximum(root);
}

int BinarySearchTree::depth(Node* w) {
    if (w == nullptr) {
        return 0;
    }
    int ldepth = depth(w->left);
    int rdepth = depth(w->right);
    if (ldepth > rdepth) {
        return ldepth + 1;
    }
    return rdepth + 1;
}

int BinarySearchTree::depth() {
    return depth(root);
}

int* BinarySearchTree::search(Node* w, const int& x) {
    while (w != nullptr) {
        if (x == w->key) {
            return &w->key;
        }
        else if (x < w->key) {
            w = w->left;
        }
        else {
            w = w->right;
        }
    }
    return nullptr;
}

int* BinarySearchTree::search(const int& x) {
    return search(root, x);
}

int* BinarySearchTree::searchRecursive(Node* w, const int& x) {
    if (w == nullptr || w->key == x) {
        return &w->key;
    }
    if (w->key <= x) {
        return searchRecursive(w->right, x);
    }
    return searchRecursive(w->left, x);
}

int* BinarySearchTree::searchRecursive(const int& x) {
    return searchRecursive(root, x);
}

void BinarySearchTree::inorder(Node* w) {
    if (w != nullptr) {
        inorder(w->left);
        visit(w);
        inorder(w->right);
    }
}

void BinarySearchTree::inorder() {
    inorder(root);
}

void BinarySearchTree::preorder(Node* w) {
    if (w != nullptr) {
        visit(w);
        preorder(w->left);
        preorder(w->right);
    }
}

void BinarySearchTree::preorder() {
    preorder(root);
}

void BinarySearchTree::postorder(Node* w) {
    if (w != nullptr) {
        postorder(w->left);
        postorder(w->right);
        visit(w);
    }
}

void BinarySearchTree::postorder() {
    postorder(root);
}

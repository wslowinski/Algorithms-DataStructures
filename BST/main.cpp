#include "BinaryTree.h"

int main() {
    BinarySearchTree BST;
    int n, x;
    std::cin >> n;
    while (std::cin >> x) {
        BST.insert(x);
    }
    
    std::cout << BST.size() << " " << BST.depth() << " " << BST.minimum() 
        << " " << BST.maximum() << std::endl;
    BST.preorder();
    for (int i = 1; i <= 9; i++) {
        if (BST.searchRecursive(i) == nullptr) {
            std::cout << "No" << std::endl;
        }
        else std::cout << "Yes" << std::endl;
    }
    return 0;
}

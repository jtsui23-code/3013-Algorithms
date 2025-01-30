#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    
    Node* insertHelper(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }
        
        return node;
    }
    
    Node* searchHelper(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }
        
        if (value < node->data) {
            return searchHelper(node->left, value);
        }
        return searchHelper(node->right, value);
    }
    
    void inorderHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        
        inorderHelper(node->left);
        std::cout << node->data << " ";
        inorderHelper(node->right);
    }
    
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}
    
    void insert(int value) {
        root = insertHelper(root, value);
    }
    
    bool search(int value) {
        return searchHelper(root, value) != nullptr;
    }
    
    void inorder() {
        inorderHelper(root);
        std::cout << std::endl;
    }
    
    // TODO: Implement remove method
    void remove(int value) {
        // Your implementation here
    }
};

int main() {
    BinarySearchTree bst;
    
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    
    std::cout << "Inorder traversal: ";
    bst.inorder();
    
    std::cout << "Searching for 30: " << (bst.search(30) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 60: " << (bst.search(60) ? "Found" : "Not found") << std::endl;
    
    return 0;
}
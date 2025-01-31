/*****************************************************************************
*                    
*  Author:           Jack Tsui
*  Email:            jtsui1110@my.msutexas.edu
*  Label:            03-A03
*  Title:            BST - Remove
*  Course:           3013 Adv Algorithms
*  Semester:         Spring 2025
* 
*  Description:
*        This program demonstrates the removal of a node from a Binary Search Tree (BST).
* 
*  Usage:
*       g++ JackBST.cpp -o JackBST.exe
*      ./[EXECUTABLE] 
* 
*  Files:            
*                    JackBST.cpp
*                    game.exe 
*                    
*
*****************************************************************************/

#include <iostream>

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    bool search(Node* node, int val) const {
        if (node == nullptr) {
            return false;
        }

        if (val == node->data) {
            return true;
        } else if (val < node->data) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }

    void inorder(Node* node) const {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }


    /**
     * Private: remove
     * 
     * Description:
     *      Removes a node with the specified value from the Binary Search Tree (BST).
     *      Handles three cases: node with no children, node with one child, and node with two children.
     *      Ensures the BST remains properly ordered after removal.
     * 
     * Parameters:
     *      - Node* node: The current node being examined (starts with the root of the subtree).
     *      - int val: The value of the node to remove.
     * 
     * Returns:
     *      - Node*: The updated subtree after removal (or nullptr if the node is deleted).
     */
    Node* remove(Node* node, int val) {

        // Checks if the node is empty before proceeding down the 
        // tree to find the node to remove.
        if (node == nullptr) {
            return node;
        }

        // Traverses left if the value is less than the current node's value.
        if (val < node->data) {
            node->left = remove(node->left, val);
        } 

        // Traverses right if the value is greater than the current node's value.
        else if (val > node->data) {
            node->right = remove(node->right, val);
        } 

        // If the value is equal to the current node's value, then the node is removed.
        else 
        {
            // If the node has only one child to the right, then the node is removed and 
            // the right child is returned.
            // Have to return the right child because the parent's nodes have to 
            // updated to point to the right child.
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } 

            // If the node has only one child to the left, then the node is removed and 
            // the left child is returned.
            // Have to return the right child because the parent's nodes have to 
            // updated to point to the left child.
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Handles the case where the node has two children.
            // The node is replaced with the smallest node in the right subtree.
            // It has to be the smallest value on the right or the tree will not be
            // ordered correctly. 
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) const {
        return search(root, val);
    }

    void inorder() const {
        inorder(root);
        std::cout << std::endl;
    }

    void remove(int val) {
        root = remove(root, val);
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << "Inorder Traversal: ";
    bst.inorder();

    bst.remove(3);
    std::cout << "Inorder Traversal after removing 3: ";
    bst.inorder();

    return 0;
}
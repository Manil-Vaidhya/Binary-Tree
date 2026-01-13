#include <iostream>
using namespace std;

class BST {
private:
    int data;
    BST* left;
    BST* right;

public:
    BST(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value) {
        if (value < data) {
            if (left == nullptr)
                left = new BST(value);
            else
                left->insert(value);
        } else {
            if (right == nullptr)
                right = new BST(value);
            else
                right->insert(value);
        }
    }

    void inorder() {
        if (left != nullptr)
            left->inorder();
        cout << data << " ";
        if (right != nullptr)
            right->inorder();
    }

    // Find minimum value node in a subtree
    BST* findMin() {
        BST* current = this;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Delete a node and return the new subtree root
    BST* deleteNode(int value) {
        // Search in left subtree
        if (value < data) {
            if (left != nullptr)
                left = left->deleteNode(value);
        }
        // Search in right subtree
        else if (value > data) {
            if (right != nullptr)
                right = right->deleteNode(value);
        }
        // Found the node to delete
        else {
            // Case 1: Leaf node (no children)
            if (left == nullptr && right == nullptr) {
                delete this;
                return nullptr;
            }
            // Case 2: One child (right only)
            else if (left == nullptr) {
                BST* temp = right;
                delete this;
                return temp;
            }
            // Case 3: One child (left only)
            else if (right == nullptr) {
                BST* temp = left;
                delete this;
                return temp;
            }
            // Case 4: Two children
            else {
                BST* successor = right->findMin();
                data = successor->data;
                right = right->deleteNode(successor->data);
            }
        }
        return this;
    }
};

int main() {
    BST* tree = new BST(50);

    tree->insert(30);
    tree->insert(70);
    tree->insert(20);
    tree->insert(40);
    tree->insert(60);
    tree->insert(80);

    cout << "Original BST (Inorder): ";
    tree->inorder();
    cout << endl;

    cout << "\nDeleting 20 (leaf node)..." << endl;
    tree = tree->deleteNode(20);
    cout << "After deletion: ";
    tree->inorder();
    cout << endl;

    cout << "\nDeleting 30 (node with two children)..." << endl;
    tree = tree->deleteNode(30);
    cout << "After deletion: ";
    tree->inorder();
    cout << endl;

    cout << "\nDeleting 50 (root node)..." << endl;
    tree = tree->deleteNode(50);
    cout << "After deletion: ";
    tree->inorder();
    cout << endl;

    return 0;
}

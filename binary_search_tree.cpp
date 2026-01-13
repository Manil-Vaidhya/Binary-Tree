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
    void preorder(){
        cout<< data <<" ";
        if(left!= nullptr)
            left->preorder();
        if(right!= nullptr)
            right->preorder();
    }
};

int main() {
    BST tree(50);
    
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;
    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << endl;
    
    

    return 0;
}

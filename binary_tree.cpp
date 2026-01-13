#include <iostream>
#include <queue>
using namespace std;

class BinaryTree {
private:
    int data;
    BinaryTree* left;
    BinaryTree* right;

public:
    BinaryTree(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value) {
        queue<BinaryTree*> q;
        q.push(this);

        while (!q.empty()) {
            BinaryTree* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = new BinaryTree(value);
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = new BinaryTree(value);
                return;
            } else {
                q.push(current->right);
            }
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
        if (left!= nullptr)
            left->preorder();
        if (right!= nullptr)
            right->preorder();
    }
};

int main() {
    BinaryTree tree(1);

    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;
    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << endl;
    return 0;
}

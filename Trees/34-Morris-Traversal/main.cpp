#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> inorderTraversal(Node* root) {
    vector<int> inorder;
    Node* cur = root;
    
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            inorder.push_back(cur->data);
            cur = cur->right;
        } else {
            Node* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = nullptr;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }

    return inorder;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

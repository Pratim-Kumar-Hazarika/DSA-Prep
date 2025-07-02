#include <iostream>
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

class Solution {
public:
    void flatten(Node* root) {
        if (root == nullptr) return;

        Node* cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                Node* prev = cur->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

void printFlattened(Node* root) {
    while (root != nullptr) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}
//         1
//       /   \
//      2     5
//     / \     \
//    3   4     6

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Solution sol;
    sol.flatten(root);

    printFlattened(root); // Should print: 1 2 3 4 5 6

    return 0;
}

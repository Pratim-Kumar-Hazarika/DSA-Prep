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
    Node* searchBST(Node* root, int val) {
        while (root != nullptr && root->data != val) {
            root = (val < root->data) ? root->left : root->right;
        }
        return root;
    }
};


int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution sol;
    Node* result = sol.searchBST(root, 31);

    if (result) {
        cout << "Found node with value: " << result->data << endl;
    } else {
        cout << "Value not found in BST." << endl;
    }

    return 0;
}

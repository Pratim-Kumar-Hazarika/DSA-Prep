#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    Node* insertIntoBST(Node* root, int val) {
        if (root == NULL) return new Node(val);
        Node* curr = root;
        while (true) {
            if (curr->val <= val) {
                if (curr->right) curr = curr->right;
                else {
                    curr->right = new Node(val);
                    break;
                }
            } else {
                if (curr->left) curr = curr->left;
                else {
                    curr->left = new Node(val);
                    break;
                }
            }
        }
        return root;
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

int main() {
    Solution sol;

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    cout << "Before insertion: ";
    sol.inorder(root);
    cout << endl;

    int newValue = 8;
    sol.insertIntoBST(root, newValue);

    cout << "After inserting " << newValue << ": ";
    sol.inorder(root);
    cout << endl;

    return 0;
}

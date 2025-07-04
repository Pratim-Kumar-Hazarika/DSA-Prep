#include <iostream>
#include <vector>
#include <climits>
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
    Node* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    Node* build(vector<int>& A, int &i, int bound) {
        if (i == A.size() || A[i] > bound) return nullptr;
        Node* root = new Node(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

int main() {
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Node* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    sol.inorder(root); // Should print sorted order: 1 5 7 8 10 12
    cout << endl;

    return 0;
}

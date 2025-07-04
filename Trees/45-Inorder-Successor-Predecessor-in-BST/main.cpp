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

// Insert into BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Inorder Successor (smallest node > val)
Node* findSuccessor(Node* root, int val) {
    Node* successor = nullptr;
    while (root) {
        if (val >= root->val) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

    //        20
    //      /    \
    //    10      30
    //   /  \    /  \
    //  5   15  25  35

// Inorder Predecessor (largest node < val)
Node* findPredecessor(Node* root, int val) {//15
    Node* predecessor = nullptr;
    while (root) {
        if (val <= root->val) {
            root = root->left;
        } else {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

int main() {
    vector<int> values = {20, 10, 30, 5, 15, 25, 35};
    ///5 10 15 20 25 30 35
    Node* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }

    int key = 15;
    Node* succ = findSuccessor(root, key);
    Node* pred = findPredecessor(root, key);

    cout << "For key = " << key << ":\n";
    cout << "Successor = " << (succ ? to_string(succ->val) : "None") << endl;
    cout << "Predecessor = " << (pred ? to_string(pred->val) : "None") << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    int countNodes(Node* root) {
        if (root == NULL) return 0;

        int lh = findlh(root);
        int rh = findrh(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findlh(Node* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    int findrh(Node* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }
    //TC - O(logn^2)
    //SC - O(logn)
};
    //         1
    //       /   \
    //      2     3
    //     / \   /
    //    4   5 6

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    Solution sol;
    cout << "Total Nodes: " << sol.countNodes(root) << endl;

    return 0;
}

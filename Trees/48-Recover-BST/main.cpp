#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    Node* first;
    Node* prev;
    Node* middle;
    Node* last;
public:
    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root->left);
        if(prev != NULL && (root->val < prev->val)){
            if(first == NULL){
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(Node* root) {
        first = middle = last = NULL;
        prev = new Node(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
        Original BST:     3
                         / \
                        1   4
                           /
                          2
        Swapped BST:  (nodes 2 and 3 are swapped)
    */

    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    cout << "Before recovery (inorder): ";
    printInorder(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "After recovery (inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}

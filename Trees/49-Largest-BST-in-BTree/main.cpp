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

class Brtue {
    public:
        bool isBst(Node* root , long minVal, long maxVal){
            if(!root) return true;
            if(root->val <= minVal || root->val >= maxVal) return false;
            return isBst(root->left, minVal, root->val) && isBst(root->right, root->val, maxVal);
        }
        int countNodes(Node* root){
            if(!root) return 0;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
        int largestBst(Node* root){
            if(!root) return 0;
            if(isBst(root,LONG_MIN,LONG_MAX)){
                return countNodes(root);
            }
            return max(largestBst(root->left),largestBst(root->right));
        }

};
void printResult(Node* root) {
    Brtue sol;
    cout << "Largest BST size in the tree: " << sol.largestBst(root) << endl;
}

int main() {
    /*
        Example:
               10
              /  \
             5    15
            / \     \
           1   8     7

        The largest BST is:
            5
           / \
          1   8
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    printResult(root);

    return 0;
}
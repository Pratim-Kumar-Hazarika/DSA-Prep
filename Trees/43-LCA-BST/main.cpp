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
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root == NULL) return NULL;
        int curr = root->val;
        if(curr < p->val && curr < q->val){
                return lowestCommonAncestor(root->right,p,q);
        }
        if(curr > p->val && curr > q->val){
              return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};
 /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5
    */


int main(){
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    Solution sol;
    Node* p = root->left; // 2
    Node* q = root->right; // 8
    Node* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}
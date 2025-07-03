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
    bool ans(Node* root, long minVal, long maxVal){
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        return ans(root->left, minVal,root->val) && ans(root->right, root->val,maxVal);
    }
    bool isValidBST(Node* root) {
        return ans(root,LONG_MIN, LONG_MAX);
    }
};
int main(){
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(2);

    Solution sol;
    bool result = sol.isValidBST(root);

    if(result){
        cout << "The tree is a valid BST." << endl;
    }else{
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
            1
           /  \
          2     3
         / \   / \
        4  5  6   7
           /\
          8  9
 */
class Solution {
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    };
    void addLeftBoundary(Node* root , vector<int>&res){
        Node* cur = root->left;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    };
    void addRightBoundary(Node* root , vector<int>&res){
        Node* cur = root->right;
        vector<int> temp;
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for(int i = temp.size() -1 ; i>=0 ; i--){
            res.push_back(temp[i]);
        }
    };
    void addLeafNodes(Node* root , vector<int>&res){
        if(isLeaf(root)) res.push_back(root->data);
        if(root->left) addLeafNodes(root->left, res);
        if(root->right) addLeafNodes(root->right,res);
    };
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(root == NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root,res);
        addLeafNodes(root,res);
        addRightBoundary(root,res);
        return res;
        
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    Solution s;
    vector<int> ans = s.boundaryTraversal(root);
    for(int num : ans){
        cout  << num << " ";
    }

    return 0;
}
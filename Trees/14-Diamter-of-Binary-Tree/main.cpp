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


//         1
//       /   \
//      2     3
//           / \
//          6   7

class Solution {
public:
    int diameterOfBinaryTree(Node* root) {
        int d = 0;
        height(root,d);
        return d;
    }
    private:
    int height(Node* root, int &d){
        if(!root){
            return 0;

        }
        int lh = height(root->left,d);
        int rh = height(root->right,d);
        d = max(d,lh+rh);
        return 1 + max(lh,rh);
    }
    
};
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // NaiveSolution sol;
    Solution sol;
    cout <<  sol.diameterOfBinaryTree(root) << endl;
    return 0;
}
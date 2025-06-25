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

class NaiveSolution {
public:
    int maxDepth(Node* root){
        if(root== NULL)return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh,rh);
    }
    bool isBalanced(Node* root) {
        if(root == NULL) return true;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        if(abs(lh-rh) > 1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right) return false;
        return true;

    }
};

class Optimal {
public:
    int maxDepth(Node* root){
        if(root== NULL)return 0;
        int lh = maxDepth(root->left);
        if(lh == -1) return -1;
        int rh = maxDepth(root->right);
        if(rh == -1) return -1;
        if(abs(lh - rh) >1) return -1;
        return 1 + max(lh,rh);
    }
    bool isBalanced(Node* root) {
      return maxDepth(root) != -1;

    }
};
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // NaiveSolution sol;
    Optimal sol;
    cout <<  sol.isBalanced(root) << endl;
    return 0;
}
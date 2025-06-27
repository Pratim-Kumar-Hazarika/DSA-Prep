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
//         1
//       /   \
//      2     3
//     / \   
//    4   5 
//       / \ 
//      6   7
*/

bool getPath(Node* root , vector<int> &ans , int x){
    if(!root){
        return false;
    }
    ans.push_back(root->data);
    if(root->data == x) return true;
    if(getPath(root->left, ans,x) || getPath(root->right,ans,x)){
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> rootToNodePath(Node* root, int x){
    vector<int> ans;
    getPath(root ,ans,x);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    vector<int> ans = rootToNodePath(root,7);
    for(int num : ans){
        cout << num << "->";
    }
    return 0;
}

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
//      2     2
//     / \   / \
//    4   5 5   4


bool isSym(Node* left , Node* right){
    if(left == NULL || right == NULL) return left == right;
    if(left->data != right->data) return false;
    return isSym(left->left , right->right) && isSym(left->right , right->left);
}
bool isSymmetric(Node* root){
    return root == NULL || isSym(root->left, root->right);
};
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    cout << isSymmetric(root) << endl;
    return 0;
}
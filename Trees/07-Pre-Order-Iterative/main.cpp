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
//     / \   / \
//    4   5 6   7

//Pre-order Traversal (Root Left Right)- > 1 2 4 5 3 6 7
void preOrderIterative(Node* node){
    if(node == NULL){
        return;
    }
    cout << node->data << " ";
    preOrderIterative(node->left);
    preOrderIterative(node->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preOrderIterative(root);
    return 0;
}
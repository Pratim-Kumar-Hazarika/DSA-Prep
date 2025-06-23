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

//In-order Traversal (Left Root Right)- > 4 2 5 1 6 3 7
void inOrder(Node* node){
    if(node == NULL){
        return;
    }
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    inOrder(root);
    return 0;
}
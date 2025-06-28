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
void childrenSumProperty(Node* node){
    if(node == NULL || (node->left == NULL && node->right == NULL)) return;

    int childSum = 0;
    if(node->left) childSum += node->left->data;
    if(node->right) childSum += node->right->data;

    if(childSum < node->data) {
        if(node->left) node->left->data = node->data;
        if(node->right) node->right->data = node->data;
    }

    childrenSumProperty(node->left);
    childrenSumProperty(node->right);

    int total = 0;
    if(node->left) total += node->left->data;
    if(node->right) total += node->right->data;

    if(node->left || node->right) node->data = total;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    childrenSumProperty(root);
    cout << "Inorder traversal after transformation:\n";


    return 0;
}

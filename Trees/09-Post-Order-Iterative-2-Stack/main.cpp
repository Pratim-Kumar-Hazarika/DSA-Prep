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

//Post-order Traversal (Left Right Root)- >4 5 2 6 7 3 1
vector<int> postOrder(Node* node){
        vector<int> ans ;
        if(node == NULL) return ans;
        stack<Node*> st1, st2;
        st1.push(node);
        while(!st1.empty()){
            node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left != NULL){
                st1.push(node->left);
            }
            if(node->right != NULL){
                st1.push(node->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;  
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans=   postOrder(root);
    for(int num : ans){
        cout << num << " ";
    }
    return 0;
}
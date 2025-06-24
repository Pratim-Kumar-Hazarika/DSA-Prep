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

//In-order Traversal (Root Left Right)- >4 2 5 1 6 3 7
vector<int> inOrderTraversal(Node* root) {
      vector<int> ans;
      if(root == NULL) return ans;
      stack<Node*> st;
      Node* node =root;
      while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
      }
      return ans;
    }


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = inOrderTraversal(root);
    for(int nums : ans){
        cout << nums << " ";
    }
    return 0;
}
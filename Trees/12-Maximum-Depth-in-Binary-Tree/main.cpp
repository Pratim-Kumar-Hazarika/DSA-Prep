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


//Level Order
 int maxDepth(Node* root) {
        if(root == NULL) return 0;
        queue<Node*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()){
          int size = q.size();
          for(int i = 0 ; i< size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
          }
          level++;
        }
        return level;
    }

int maxDepthRecursive(Node* root){
    if( root == NULL) return 0;
    int lh = maxDepthRecursive(root->left);
    int rh = maxDepthRecursive(root->right);
    return 1 + max(lh,rh);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << maxDepth(root) << endl;
    return 0;
}
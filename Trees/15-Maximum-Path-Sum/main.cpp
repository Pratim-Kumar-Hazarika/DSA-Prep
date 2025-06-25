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
//      2     30
//           / \
//          60   70

int maxPath(Node* root , int &sum){
    if(root == NULL) return 0;
    int lh = maxPath(root->left , sum);
    int rh = maxPath(root->right , sum);
    if(lh < 0) lh = 0;
    if(rh < 0) rh = 0;
    sum = max(sum, root->data + lh + rh);
    return root->data + max(lh , rh);
}
int maxPathSum(Node* root){
    int sum = INT_MIN;
    maxPath(root,sum);
    return sum;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(30);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    /// 160
    cout << maxPathSum(root) << endl;
    return 0;
}
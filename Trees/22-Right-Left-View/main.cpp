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


void recurLeft(Node* root , vector<int>& ds, int level){
    if(root == NULL) return;
    if(ds.size() == level){
        ds.push_back(root->data);
    }
    recurLeft(root->left, ds,level+1);
    recurLeft(root->right , ds, level+1);
  
};
vector<int> leftSideView(Node* root){
    vector<int> res;
    recurLeft(root,res,0);
    return res;
}


void recurRight(Node* root , vector<int>& ds, int level){
    if(root == NULL) return;
    if(ds.size() == level){
        ds.push_back(root->data);
    }
    recurRight(root->right , ds, level+1);
    recurRight(root->left, ds,level+1);
};
vector<int> rightSideView(Node* root){
    vector<int> res;
    recurRight(root,res,0);
    return res;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> leftView = leftSideView(root);
    vector<int> rightView = rightSideView(root);
     cout << "Left" << endl;
    for(int x : leftView){
       cout << x << " ";
    }
    
    cout << "\nRight" << endl;
    for(int x : rightView){
       cout << x << " ";
    }
    return 0;
}
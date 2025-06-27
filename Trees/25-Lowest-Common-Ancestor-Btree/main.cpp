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

class SolutionBrute {
public:
    bool find(Node* root, Node*p ,vector<Node*>& ans){
        if(!root){
            return false;
        }
        ans.push_back(root);
        if(root == p){
            return true;
        }
        if(find(root->left,p,ans) || find(root->right, p ,ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    vector<Node*> findPath(Node* root, Node* p){
        vector<Node*> ans ;
        find(root,p,ans);
        return ans;
    }
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
            if(root == NULL || root == p || root == q){
                return root;
            }
           vector<Node*> p1 =  findPath(root,p); // TC : O(N) SC : O(N)
           vector<Node*> p2 =  findPath(root,q);// TC : O(N) SC : O(N)
            Node* lca = NULL;
            int i = 0;
            while(i < p1.size() && i < p2.size() && p1[i] == p2[i]){
                lca= p1[i];
                i++;
            }
            return lca;
           
    }
};
 Node* optimal(Node* root, Node* p, Node* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        Node* left = optimal(root->left, p ,q);
        Node* right = optimal(root->right,p,q);
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        return root;
    }
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    Node* x = optimal(root,root->left->left ,root->left->right->right);
    cout << x->data << "";
    return 0;
}

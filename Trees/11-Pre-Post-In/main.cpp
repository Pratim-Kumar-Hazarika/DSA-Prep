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

class Solution {
    public:
       void preInPostTraversal(Node* root){
            stack<pair<Node*,int>> st;
            st.push({root,1});
            vector<int> pre , post , in;
            while(!st.empty()){
                auto it = st.top();
                st.pop();
                if(it.second == 1){
                    pre.push_back(it.first->data);
                    it.second++;
                    st.push(it);
                    if(it.first->left){
                        st.push({it.first->left ,1});
                    }
                }
                else if(it.second == 2){
                    in.push_back(it.first->data);
                    it.second++;
                    st.push(it);
                    if(it.first->right){
                        st.push({it.first->right,1});
                    }
                }else{
                    post.push_back({it.first->data});
                }
            }

             // Print traversals
            cout << "Preorder: ";
            for (int val : pre) cout << val << " ";
            cout << "\nInorder: ";
            for (int val : in) cout << val << " ";
            cout << "\nPostorder: ";
            for (int val : post) cout << val << " ";
            cout << endl;
        }
};
//TC -> O(3 X N);
//TC -> O(4 N)
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    sol.preInPostTraversal(root);
    return 0;
}
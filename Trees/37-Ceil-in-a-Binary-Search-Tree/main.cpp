#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
public:
    int findCeil(Node* root, int key) {
       int ceil = -1;
        while(root){
            if(root->data == key){
                ceil = root->data;
                return ceil;
            }
            if(key > root->data){
                root = root->right;
            }else{
                ceil = root->data;
                root = root->left;
            }
        }

       return ceil;
    }
};


int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution sol;
    int ans = sol.findCeil(root, 5);

    cout << ans << endl;

    return 0;
}

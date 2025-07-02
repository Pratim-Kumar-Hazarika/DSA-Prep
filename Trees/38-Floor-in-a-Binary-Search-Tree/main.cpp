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
    int findFloor(Node* root, int key) {
       int floor = -1;
        while(root){
            if(root->data == key){
                floor = root->data;
                return floor;
            }
            if(key > root->data){
                floor = root->data;
                root = root->right;
            }else{
                root = root->left;
            }
        }

       return floor;
    }
};


int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution sol;
    int ans = sol.findFloor(root, 5);

    cout << ans << endl;

    return 0;
}

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
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
    */

vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        bool isLeft = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                int index = isLeft ? i : size-1-i;
                level[index] = node->data;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            isLeft = !isLeft;
            ans.push_back(level);
        }
        return ans;
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for(const auto& x : ans){
        for(int num : x){
            cout << num << " ";
        }
    }

    return 0;
}
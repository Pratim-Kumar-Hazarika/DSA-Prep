#include<iostream>
#include<set>
#include <map> 
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
    //       /     / \
    //      8     9  10
vector<vector<int>> verticalTraversal(Node* root){
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int x = p.second.first, y  = p.second.second;
        nodes[x][y].insert(node->data);
       if(node->left) q.push({node->left,{x-1, y+1}});
       if(node->right) q.push({node->right , {x+1,y+1}});
    }
    for(auto p : nodes){
        vector<int> col;
        for(auto i : p.second){
            col.insert(col.end(), i.second.begin(), i.second.end());
        }
        ans.push_back(col);
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

    root->left->right->left = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<vector<int>> ans = verticalTraversal(root);
    for(const auto& i : ans){
        for(const auto& x : i){
            cout << x << " ";
        }
    }

   return 0;
}
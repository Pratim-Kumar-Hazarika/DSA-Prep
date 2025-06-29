#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Node* markParent(unordered_map<Node*,Node*> &parent_track,
    Node* root, int value){
        queue<Node*> q;
        Node* res;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->val == value) res = node;
            if(node->left){
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int findMaxDistance(  unordered_map<Node*,Node*> &parent_track,Node* start){
        queue<Node*> q;
        q.push(start);
        unordered_map<Node*, bool> visited;
        visited[start] = true;
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            int fl =0;
            for(int i = 0 ; i < size ; i++){
                auto node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]= true;
                    fl =1;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]= true;
                    fl =1;
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node] ]= true;
                    fl =1;
                }
            }
            if(fl){
                maxi++;
            }
        }
        return maxi;
    }
    int amountOfTime(Node* root, int start) {
        unordered_map<Node*,Node*> parent_track;
        Node* startNode = markParent(parent_track,root,start);
        return findMaxDistance(parent_track,startNode);
    }
};
    //     3
    //    / \
    //   5   1
    //  / \ / \
    // 6  2 0  8
    //   / \
    //  7   4


int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution s;
    cout << s.amountOfTime(root, 5) << endl;

    return 0;
}

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
//     /       \  
//    4         5

*/

int maxWidth(Node*root){
    int ans = 0;
    if(root == NULL) return 0;
    queue<pair<Node*, long long >> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        long long mini = q.front().second;
        int first, last;
        for(int i = 0 ; i< size ; i++){
            long long cur_id = q.front().second - mini;
            Node* node = q.front().first;
            q.pop();
            if( i == 0) first = cur_id;
            if( i == size-1) last = cur_id;
            if(node->left){
                q.push({node->left, cur_id*2+1});
            }
            if(node->right){
                q.push({node->right, cur_id*2+2});
            }
        }
        ans  = max(ans,(int)(last-first+1));
    }
    return ans;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
   root->right->right = new Node(5);

    cout << maxWidth(root) << "";
    return 0;
}

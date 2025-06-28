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

    void markParent(unordered_map<Node*, Node*>& parent_track, Node* root) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front(); q.pop();
            if (current->left) {
                q.push(current->left);
                parent_track[current->left] = current;
            }
            if (current->right) {
                q.push(current->right);
                parent_track[current->right] = current;
            }
        }
    }

    vector<int> distanceK(Node* root, Node* target, int k) {
        unordered_map<Node*, Node*> parent_track;
        markParent(parent_track, root);
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        int current_level = 0;
        q.push(target);
        visited[target] = true;
        while (!q.empty()) {
            int size = q.size();
            if (current_level == k) break;
            current_level++;
            for (int i = 0; i < size; i++) {
                Node* curr_node = q.front(); q.pop();
                if (curr_node->left && !visited[curr_node->left]) {
                    q.push(curr_node->left);
                    visited[curr_node->left] = true;
                }
                if (curr_node->right && !visited[curr_node->right]) {
                    q.push(curr_node->right);
                    visited[curr_node->right] = true;
                }
                if (parent_track.count(curr_node) && !visited[parent_track[curr_node]]) {
                    q.push(parent_track[curr_node]);
                    visited[parent_track[curr_node]] = true;
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            result.push_back(node->val);
        }
        return result;
    }

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

    Node* target = root->left; 
    int k = 2;

    vector<int> result = distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target " << target->val << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

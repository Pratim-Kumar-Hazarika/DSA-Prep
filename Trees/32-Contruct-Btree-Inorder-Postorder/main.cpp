#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* build(vector<int>& inorder, int is, int ie,
                vector<int>& postorder, int ps, int pe,
                map<int, int>& hm) {

        if (ps > pe || is > ie) return nullptr;

        Node* root = new Node(postorder[pe]);
        int inRoot = hm[root->val];
        int numsLeft = inRoot - is;

        root->left = build(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hm);
        root->right = build(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return nullptr;

        map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1,
                     hm);
    }
};


void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    Node* root = sol.buildTree(inorder, postorder);

    cout << "Level order output: ";
    printLevelOrder(root); // Expected: 3 9 20 null null 15 7
    return 0;
}

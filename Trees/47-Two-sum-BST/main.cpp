#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

class Bst {
public: 
    bool reverse = true;
    stack<TreeNode*> st;

    Bst(TreeNode* root, bool _reverse) {
        this->reverse = _reverse; // ✅ Fix here
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }

private:
    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = (reverse ? root->right : root->left);
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        Bst l(root, false); // left pointer (smallest first)
        Bst r(root, true);  // right pointer (largest first)

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << boolalpha << sol.findTarget(root, 9) << endl;  // Output: true
    cout << boolalpha << sol.findTarget(root, 28) << endl; // Output: false

    return 0;
}

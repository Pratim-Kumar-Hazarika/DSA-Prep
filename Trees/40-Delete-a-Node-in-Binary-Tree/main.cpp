
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    Node* deleteNode(Node* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return deleteNode(root);
        }
        Node* dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = deleteNode(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
               if(root->right != NULL && root->right->val == key){
                root->right = deleteNode(root->right);
                    break;
               }else{
                 root = root->right;
               }
            }
        }
        return dummy;
    }
    Node* deleteNode(Node* root){
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }
        Node* rightChild = root->right;
        Node* lastRightChild = findLastRight(root->left);
        lastRightChild->right = rightChild;
        return root->left;
    }
    Node* findLastRight(Node* root){
        if(root->right == NULL){
            return root;
        }
        return findLastRight(root->right);
    }
};

   /*
            5
           / \
          3   6
         / \   \
        2   4   7
    */
int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    Solution sol;

    int keyToDelete = 3;
    root = sol.deleteNode(root, keyToDelete);

    // In-order traversal to verify the result
    function<void(Node*)> inorder = [&](Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    };

    cout << "In-order traversal after deleting " << keyToDelete << ": ";
    inorder(root);
    cout << endl;

    return 0;
}

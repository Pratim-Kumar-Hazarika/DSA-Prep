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


    void inorder(Node* root, int& k, int& res){
        if (!root) return;
        inorder(root->left, k, res);
        k--;
        if (k == 0) {
            res = root->val;
            return;
        }
        inorder(root->right, k, res);
    }

    int kthSmallest(Node* root, int k) {
        int res = -1;
        inorder(root, k, res);
        return res;
    }

   /*
           5
          / \
         3   6
        / \
       2   4
    */
   /*
    Inorder is 2 3 4 5 6 : 
    kth smallest of 2 is 3
    kth largest of 2 is 5
   */
void countNodes(Node* root , int & N){
    if (!root) return;
    countNodes(root->left, N);
    N++;
    countNodes(root->right, N);

}
int kthLargest(Node* root, int k){
    int N = 0;
    countNodes(root, N);
    int target = N - k + 1; // Convert kth largest to kth smallest
    int res = -1;
    inorder(root, target, res);
    return res;
}
int main() {
  
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    cout << kthSmallest(root, 2) << endl; // Output: 2

    cout << kthLargest(root, 2) << endl; // Output: 5
    return 0;
}

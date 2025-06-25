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

//Node* p
//         1
//       /   \
//      2     30
//           / \
//          60   70

//Node* q
//         1
//       /   \
//      2     30
//           / \
//          60   70

bool isSame(Node*p , Node* q){
    if(p == NULL || q == NULL){
        return p == q;
    }
    return (p->data == q->data ) & isSame(p->left , q->left) && isSame(p->right, q->right);
}

int main(){
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(30);
    p->right->left = new Node(60);
    p->right->right = new Node(70);

    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(30);
    q->right->left = new Node(60);
    q->right->right = new Node(70);

    cout << isSame(p,q) << endl;
    return 0;
}
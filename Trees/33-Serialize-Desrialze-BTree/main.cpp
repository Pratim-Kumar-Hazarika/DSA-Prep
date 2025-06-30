#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string s = "";
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curNode = q.front();
            q.pop();
            if (curNode == NULL) s.append("#,");
            else {
                s.append(to_string(curNode->val) + ',');
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        Node* root = new Node(stoi(str));
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (!getline(s, str, ',')) break;
            if (str == "#") {
                node->left = NULL;
            } else {
                Node* leftNode = new Node(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            if (!getline(s, str, ',')) break;
            if (str == "#") {
                node->right = NULL;
            } else {
                Node* rightNode = new Node(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
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
            cout << "# ";
        }
    }
    cout << endl;
}

int main() {
    // Manually build a tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    Node* deserializedRoot = codec.deserialize(serialized);
    cout << "Deserialized tree (level order): ";
    printLevelOrder(deserializedRoot);  // Expected: 1 2 3 # # 4 5

    return 0;
}

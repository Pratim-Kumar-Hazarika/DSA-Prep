#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int val1) {
        val = val1;
        next = NULL;
        random = NULL;
    }
};

  Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*,Node*> mpp;
        while(temp != NULL){ //O(N)
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){//O(N)
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }
    return mpp[head];
    //TC : O(N) + O(N) : O(2N) ( assuming hashmap is working in O(1))
    //SC : O(N) + O(N)
    }

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

// Build the list and return head
Node* createListWithRandoms() {
    vector<Node*> nodes;
    for (int val : {7, 13, 11, 10, 1}) {
        nodes.push_back(new Node(val));
    }

    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    nodes[0]->random = NULL;
    nodes[1]->random = nodes[0];
    nodes[2]->random = nodes[4];
    nodes[3]->random = nodes[2];
    nodes[4]->random = nodes[0];

    return nodes[0]; 
}

int main() {
    Node* original = createListWithRandoms();
    cout << "Original List:\n";
    printList(original);

    Node* cloned = copyRandomList(original);
    cout << "\nCloned List:\n";
    printList(cloned);


    return 0;
}

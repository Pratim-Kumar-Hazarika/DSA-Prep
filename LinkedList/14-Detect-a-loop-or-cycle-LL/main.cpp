#include <iostream>  
#include <vector> 
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* convertArrayToLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < 20) { // prevent infinite loop in cyclic case
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
}

bool hasCycleBrute(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    unordered_set<Node*> st;
    Node* temp = head;

    while (temp != NULL) {
        if (st.find(temp) != st.end()) return true;
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}

bool hasCycleOptimised(Node* head){
    if(head == NULL ) return false;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
int main() {
    
//  head
//  |
//  v
// [1] → [2] → [3] → [4] → [5] → [6]
//              ^                  |
//              |                  |
//              +------------------+

    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    Node* head = convertArrayToLL(arr2);

    // 🔁 Create a cycle: last node (6) → node with value 3
    Node* temp = head;
    Node* cycleStart = nullptr;
    Node* tail = nullptr;

    while (temp != nullptr) {
        if (temp->data == 3) cycleStart = temp;
        if (temp->next == nullptr) tail = temp;
        temp = temp->next;
    }

    if (tail && cycleStart) {
        tail->next = cycleStart;
    }

   cout << hasCycleOptimised(head) << endl;

}

#include <iostream>  
#include <vector> 
#include <unordered_set>
#include<unordered_map>
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
Node* bruteForce(Node* head){
      if(head == NULL || head->next == NULL){
            return NULL;
        }
        unordered_map<Node* , int> mpp;
        Node* temp = head;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
     return temp;
     //TC : O(N * 2(insert and find map operation) * N)
     //SC : O(N)
}
Node* optimised(Node*head){
    //1. Detect loop ( slow = slow->next , fast = fast->next->next)
    //2. Move slow to head
    //3. Move slow and fast by 1
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
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
  
    cout << optimised(head)->data << endl;

}

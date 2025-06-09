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
int bruteForce(Node*head){
    unordered_map<Node*,int> mpp;
    Node* temp = head;
    int timer = 1;

    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
             return (timer - value);
        }else{
            mpp[temp] = timer;
            timer++;
        }
        temp = temp->next;
    }
    return 0;
   // TC: O(N) on average, O(N^2) in worst case (due to hash collisions)
  //  SC: O(N)
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
    int ans =  bruteForce(head) ;
    cout << ans << endl;


}

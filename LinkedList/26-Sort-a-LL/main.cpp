#include<iostream>
#include<vector>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
};
Node* convertToLL(vector<int>&arr){
    Node* head  = new Node(arr[0]);
    Node* current = head;
    for(int i = 1; i< arr.size();i++){
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        current = newNode;
    }
    return head;
}
Node * printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
    return head;
}
Node* brute(Node*head){
    //Put all in array
    //Sort array
    //Create LL
    //return head
    vector<int> nums;
    Node*temp = head;
    while(temp != NULL){  // O(N)
        nums.push_back(temp->data);
        temp = temp->next;
    }
    sort(nums.begin(), nums.end()); // N log N
    Node* ans = convertToLL(nums); // O(N)
    return ans;
    // SC :O N + O N
}
int main(){
    vector<int> list = {1,9,4,3,6};
    Node* head = convertToLL(list);
    Node* ans = brute(head);
    printLL(ans);
}
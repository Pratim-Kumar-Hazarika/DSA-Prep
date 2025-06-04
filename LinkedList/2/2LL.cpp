#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};


Node* convetToLL(vector<int>&arr){
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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}
Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *removeTail(Node* head){
    if(head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;  
    temp->next = NULL;
    return head;
}
int main (){
    vector<int> arr = {21, 4, 6, 8, 10};
    Node* head = convetToLL(arr);
    // head = removeHead(head);
    head = removeTail(head);
    printLL(head);
   
    cout << "\nCount of nodes in the linked list: " << endl;


};
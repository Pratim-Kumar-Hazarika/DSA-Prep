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
Node *deleteKthElement(Node* head, int k){
    if(head == NULL) return head;
    if(k ==1){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node *temp = head, *prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;  

    }
    return head;
}   

Node *removeEl(Node* head, int el){
    if(head == NULL) return head;
    if(head->data == el){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head, *prev = NULL;
    while(temp != NULL){

        if(temp->data == el){
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;  

    }
    return head;
}  
int main (){
    vector<int> arr = {21, 4, 6, 8, 10};
    Node* head = convetToLL(arr);
    // head = removeHead(head);
    // head = removeTail(head);
    // head = deleteKthElement(head,3);
    // head = removeEl(head, 6);
    printLL(head);
   
    cout << "\nCount of nodes in the linked list: " << endl;


};
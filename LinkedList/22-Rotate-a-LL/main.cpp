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

  Node* rotateRight(Node* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        int length = 1;
        Node* curr = head;
        while(curr->next != NULL){ //O(N)
               length++;
             curr = curr->next;
         
           
        }
        curr->next = head;
        k = k% length;
        if(k == 0) {
            curr->next = NULL;
            return head;
        }
        k = length - k ;
        while(k--) curr = curr->next; //O(N)
        head = curr->next;
        curr->next = NULL;
        return head;
        //TC :O(2N)
        //SC :O(1)
    }
int main (){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convetToLL(arr);
    printLL(head);
   

};
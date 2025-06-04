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
int main (){
    vector<int> arr = {21, 4, 6, 8, 10};
    Node* head = convetToLL(arr);
    cout << "Linked List created successfully!" << endl;
    cout <<  head->data << endl; // Output the first element

    ///Loop through the LL
    Node* temp = head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    ///Count in LL

    int count = 0;
    Node* countLL =  head;
    while(countLL){
        count++;
        countLL = countLL->next;
    }
    cout << "\nCount of nodes in the linked list: " << count << endl;

    return 0;
};
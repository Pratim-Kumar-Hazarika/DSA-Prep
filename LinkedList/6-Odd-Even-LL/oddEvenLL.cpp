#include<iostream>  
using namespace std;

class Node {
    public:
        int data;
        Node* next; // Pointer to the next node
        Node* back; //Pointer to the previous node

        // Constructor to initialize data and set next and back to nullptr
        Node(int value){
            data = value;
            next = nullptr; // Initialize next to nullptr
            back = nullptr; // Initialize back to nullptr
        }

        // Constructor to initialize data, next, and back
        Node(int value, Node* next1, Node* back1){
            data = value; // Initialize data with value
            next = next1; // Initialize next to next1
            back = back1; // Initialize back to back1
        }
};

Node* convetArrayToDoubleLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node* newNode = new Node(arr[i], nullptr, prev);
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* bruteForce(Node* head){
    //1. Take an array 
    //2. Add the Odd elements first
    //3. Add the Even elements
    //4. Loop through the array and replace the value

    //Tc - O(n/2) + 0(n/2) + O(N) = 2N
    //Sc - O(N) vector is being used


     if(head == NULL || head->next ==NULL){
            return head; 
    }
    vector<int> arr2;
    Node* temp = head;
    //Odd Index
    while(temp != NULL && temp->next != NULL){
        arr2.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr2.push_back(temp->data);

    //Even Index
    temp = head->next;
    while(temp != NULL && temp->next != NULL){
        arr2.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr2.push_back(temp->data);

    int i = 0 ; 
    temp = head;

    while(temp!= NULL){
        temp->data = arr2[i++];
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
   //Output: [1,3,5,2,4]
   
     Node* head =  convetArrayToDoubleLL(arr);
     head = bruteForce(head);
     print(head);

  
    

    return 0;
}
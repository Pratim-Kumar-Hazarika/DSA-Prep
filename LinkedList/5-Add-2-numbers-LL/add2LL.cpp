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


Node *addTwoNumbers(Node*l1 , Node*l2){
    Node*dummyHead = new Node(-1);
    Node* curr = dummyHead;
    Node* temp1 = l1;
    Node* temp2 = l2;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){
        int sum=0;

        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        sum+= carry;
        carry = sum/10;

        Node* newNode = new Node(sum%10);
        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;

    }

    return dummyHead->next;
}
int main()
{
    vector<int> arr1 = {2,4,3};
    vector<int> arr2 = {5,6,4};
    //Output: [7,0,8]
    Node* l1 = convetArrayToDoubleLL(arr1);
    Node* l2 = convetArrayToDoubleLL(arr2);
    Node* ans = addTwoNumbers(l1,l2);
    print(ans);

    return 0;
}
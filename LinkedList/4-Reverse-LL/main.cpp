#include<iostream>  
#include <vector> 
#include <stack> 
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

void reverseWrtData(Node *head);
 Node* reverseOptimal(Node* head);
int main()
{
    vector<int> arr = {21, 4, 6, 8, 10};
    Node* head = convetArrayToDoubleLL(arr);
    head = reverseOptimal(head);
    print(head);
    //reverse LL in terms of data
    //Brute force
    //1. reverseWrtData(head);
    //2.reverseOptimal(head);

    return 0;
}


 Node* reverseOptimal(Node* head) {
    //TC->O(N)
    //SC->O(1)
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node* last = NULL;
        Node* curr = head;
        while (curr != NULL) {
            last = curr->back;
            curr->back = curr->next;
            curr->next = last;
            curr = curr->back;
        }
        return last->back;
}

void reverseWrtData(Node *head)
{
    //TC-> 0(2N)
    //SC-> O(N)
    stack<int> st;
    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    print(head);
}

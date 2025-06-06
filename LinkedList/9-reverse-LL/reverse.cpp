#include<iostream>  
#include <vector> 
#include <stack>  
using namespace std;

class Node {
    public:
        int data;
        Node* next; 
        Node* back;
        Node(int value){
            data = value;
            next = nullptr;
            back = nullptr; 
        }

      
        Node(int value, Node* next1, Node* back1){
            data = value;
            next = next1;
            back = back1;
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
    //Take a stack . Why Stack ?? Because its LIFO
    //Push data
    //Pop from stack , replace data


    stack<int> st ;
    Node* temp = head;
    //TC O(N)
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    //TC O(N)
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    //Total TC->O(2N)
    //SC->O(N) We are storing all data in stack;
    return head;
}
//Reverse A Linked List
int main()
{
    vector<int> arr = {1,2,3,4,5};
    // Output: [5,4,3,2,1]
    Node* head = convetArrayToDoubleLL(arr);
    head = bruteForce(head);
    print(head);

  
    

    return 0;
}
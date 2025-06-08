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

Node* reverse(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node* brute(Node*head){
    Node* reverseHead = reverse(head); //O(N)
    Node *temp =reverseHead;
    int carry = 1;
    while(temp != NULL){  //O(N)
        temp->data = temp->data + carry;
        if(temp->data <10){
            carry = 0;
            break;
        }else{
            temp->data= 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        head = reverse(reverseHead);
        newNode->next = head;
        return newNode;
        

    }
    return reverse(reverseHead);  //O(N)
    //TC : O(N)+O(N)+O(N) = O(3N)
    //SC : O(1)
    //Optimise the time complexity

}

int main()
{
    vector<int> arr = {1,5,9};
    //Output : 159+1 = 160 
    Node* head = convetArrayToDoubleLL(arr);
    head = brute(head);
    print(head);
  
    

    return 0;
}
#include<iostream>  
#include <vector>   
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

Node* bruteForce(Node* head, int n){
    //Take counter , increment
    //go to  counter - n places
    //delete it

    //TC  : O(len ) + O(len - N)
    //TC  : ~O(2 x len) if n == 1
    //SC  : O(1)
    if(head == NULL)return NULL;
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp =  temp->next;
    }
    if( cnt == n){
        Node* newHead = head->next;
        delete (head);
        return newHead;
    }
    int res = cnt - n;
    temp = head;
    while(temp != NULL){
        res--;
        if(res == 0){
            break;
        }
        temp = temp->next;
    }
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return head;

}
// Remove Nth Node from the end of the LinkedList
int main()
{
    vector<int> arr = {1,2,3,4,5};
    int  n = 2;
    // Output: [1,2,3,5]
    Node* head = convetArrayToDoubleLL(arr);
    head = bruteForce(head,2);
    print(head);

  
    

    return 0;
}
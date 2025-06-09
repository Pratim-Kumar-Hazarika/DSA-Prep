#include <iostream>  
#include <vector> 

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* convertArrayToLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node*temp = head;
    for(int i = 1; i< arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void print(Node* head){
    Node* temp  = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* brute(Node* head){
    //Traverse find N
    //N/2;
    //Traverse to N/2 node
    //middle = temp->next;
    //temp->next = temp->next->next
    //delete  middle;
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head; int n = 0;
    while(temp != NULL){ //O(N)
        n++;
        temp = temp->next;
       
    }
       int res  = floor(n/2);
        temp = head;
        while(temp != NULL){ //O(N/2)
            res--;
            if(res == 0){
                Node* middle = temp->next;
                temp->next = temp->next->next;
                delete middle;
                break;
            }
            temp = temp->next;
        }
        //TC :O(N) +O(N/2)
        return head;
}

Node* optimised(Node*head){
    if(head == NULL || head->next == NULL) return head;
    //Skip one step of slow that it point to previous
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}
int main(){
    vector<int> arr= {1,3,4,7,1,2,6}; //output : 1,2,3,4,1,2,6
    Node* head  = convertArrayToLL(arr);
    head = optimised(head);
    print(head);
}
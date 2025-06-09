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

Node* brute(Node*head){
     if(head == NULL) return NULL;
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){ //O(N)
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int mid = cnt/2 +1;
        while(temp != NULL){  //O(N/2)
            mid--;
            if(mid == 0){
                break;
            }
            temp = temp->next;
        }

        return temp;
        //TC : O(N + N/2);
        //SC : O(1)
}
//Tortoise & hare algorithm
Node* optimsied(Node * head){
    if(head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; 
    //TC : O(N/2)
    //SC : O(1)
}
int main(){
    vector<int> arr= {1,2,3,4,5}; //output : 3
    vector<int> arr2= {1,2,3,4,5,6}; //output : 4
    Node* head  = convertArrayToLL(arr2);
    Node*ans = optimsied(head);
    cout << ans->data << endl;
    // print(head);
}
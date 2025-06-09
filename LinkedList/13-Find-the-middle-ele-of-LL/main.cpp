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

int main(){
    vector<int> arr= {1,2,3,4,5};
    Node* head  = convertArrayToLL(arr);
    print(head);
}
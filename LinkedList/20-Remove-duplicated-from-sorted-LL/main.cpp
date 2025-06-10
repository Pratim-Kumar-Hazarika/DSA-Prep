#include<iostream> 
#include <vector>  
using namespace std;

class Node{
    public:
        int data ;
        Node* next;
        Node*back;
    Node(int val1, Node* next1, Node*back1){
        data = val1;
        next = next1;
        back = back1;
    }
      Node(int val1){
        data = val1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrayToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i< arr.size(); i++){
        Node* newNode = new Node(arr[i],nullptr,temp);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}



int main(){
    vector<int> arr ={1,1,1,2,3,3,4};
    Node *head = convertArrayToLL(arr);
   
}
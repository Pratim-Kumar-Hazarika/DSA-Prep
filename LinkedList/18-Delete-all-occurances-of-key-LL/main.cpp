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

Node* deleteAllOccurances(Node* head, int k){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == k){
            Node* toDelete = temp;
            if(temp == head){
                head = head->next;
                if(head) head->back = nullptr;
                temp = head; 
            } else {
                Node* prevNode = temp->back;
                Node* nextNode = temp->next;
                if(prevNode) prevNode->next = nextNode;
                if(nextNode) nextNode->back = prevNode;
                temp = temp->next;
            }
            delete toDelete;  
        } else {
            temp = temp->next;
        }
    }
    return head;
}
int main(){
    vector<int> arr ={10,2,10,10,5,6,10};
    Node *head = convertArrayToLL(arr);
    Node* ans = deleteAllOccurances(head,10);
    print(ans);
    
}
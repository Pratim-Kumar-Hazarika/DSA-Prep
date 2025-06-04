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

Node * deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;
}

Node *deleteTail(Node* head){
    if(head== NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prevTail = tail->back;
    prevTail->next = NULL;
    tail->back = NULL;
    delete tail;
    return head;

}

Node* removeKthElement(Node* head, int k){
    if(head == NULL) return head;
    int cnt = 0;
    Node* kthNode = head;
    while(kthNode != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        kthNode = kthNode->next;    
    }
    Node* prev = kthNode->back;
    Node* front = kthNode->next;
    if(prev == NULL && front == NULL){
        return NULL;
    }else if(prev == NULL){
       return deleteHead(head);
    
    }else if(front == NULL){
        return deleteTail(head);    
    }
    prev->next = front;
    front->back = prev;
    kthNode->next = NULL;
    kthNode-> back = NULL;
    delete kthNode;
    return head;
}

///it will never be the head;
void deleteNode(Node*temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        prev->next = NULL;
        temp->back = NULL;
        delete temp;    
        
    }
    prev->next = front;
    front->back = prev;
    temp->next = NULL;
    temp->back = NULL;
}
//Insertion of node 1. before head 2.before tail  3. before kth 4. before node

Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val, head, NULL);
    head->back = newNode;
    return newNode;
}
Node *insertBeforeTail(Node* head , int val){
    if(head->next ==  NULL){
        return insertBeforeHead(head, val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
int main(){
 vector<int> arr = {21, 4, 6, 8, 10};
    Node* head = convetArrayToDoubleLL(arr);
    // head = deleteHead(head);
    //  head = deleteTail(head);
    // head = removeKthElement(head, 3);   
    // deleteNode(head->next->next); // delete 6
    // head = insertBeforeHead(head, 100); // insert before head   
    head = insertBeforeTail(head, 100); // insert before tail
    print(head);
 return 0;
}
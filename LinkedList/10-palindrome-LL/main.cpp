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


 bool bruteForce(Node*head){
    stack<int> st ;
    Node*temp = head;

    while(temp != NULL){ //O(N)
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){ // O(N)
        if(temp->data != st.top())return false;
        temp = temp->next;
        st.pop();
    }
    return true;
    //TC : O(N) + O(N) = 2N
    //SC : O(N) : remove this extra space complexity
}

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;

}
bool optimal(Node*head){
    if(head == NULL || head->next == NULL) return true;
    //Step 1 . Find middle
    Node* slow = head;
    Node* fast = head;

    //odd  length ::                     //even length LL
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next; //O(N/2)
    }

    //Reverse after middle
    Node* newHead = reverse(slow->next);  //O(N/2)
    
    //Compare
    Node* first = head;
    Node* second = newHead;

    while(second != NULL){ //O(N/2)
        if(first->data != second->data){
            reverse(newHead); //O(N/2)
            return false;
        }
        first = first->next; 
        second = second->next;
    }
    reverse(newHead);  //O(N/2)
    return true;
    //TC - O(2N) + (N/2) ~~ O(2N)
    //SC - O(1)

}

int main()
{
    vector<int> arr = {1,2,1};
    Node* head = convetArrayToDoubleLL(arr);
    bool ans = bruteForce(head);
    // head = optimal(head);  
   if(ans){
    cout << "Its palindorme" << endl;
   }else{
     cout << "Not palindorme" << endl;
   }

  
    

    return 0;
}
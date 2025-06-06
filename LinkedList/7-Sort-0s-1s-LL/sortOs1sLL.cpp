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

Node* bruteForce(Node* head){
    ///Take 3 counters 
    //traverse increment count
    //traverse replace the data
    //TC - > O(2N) note: optmise this to O(1);
    //SC - > O(1)

    int cnt0 = 0, cnt1 = 0 , cnt2=0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            cnt0++;
        }else if(temp->data == 1){
            cnt1++;
        }else if(temp->data == 2){
            cnt2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(cnt0 !=0){
            temp->data = 0;
            cnt0--;
        }else if(cnt1 != 0){
             temp->data = 1;
             cnt1--;
        }else if(cnt2 != 0){
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;

}
Node* optimal(Node* head){
    if( head == NULL || head->next == NULL) return head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;
    
    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }else if(temp->data == 2){
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? (oneHead->next) :(twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;
    Node* newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;

}
int main()
{
    vector<int> arr = {0,1,0,1,2,1,2};
   //Output: [0,0,1,1,1,2,2]
    Node* head = convetArrayToDoubleLL(arr);
    // head = bruteForce(head);
        head = optimal(head);
    print(head);

  
    

    return 0;
}
#include<iostream>  
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

}

int main()
{
    vector<int> arr = {0,1,0,1,2,1,2};
   //Output: [0,0,1,1,1,2,2]
    Node* head = convetArrayToDoubleLL(arr);
 //  print(head);

  
    

    return 0;
}
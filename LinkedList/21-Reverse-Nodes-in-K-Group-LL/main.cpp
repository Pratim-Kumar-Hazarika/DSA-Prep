#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};


Node* convetToLL(vector<int>&arr){
    Node* head  = new Node(arr[0]);
    Node* current = head;
    for(int i = 1; i< arr.size();i++){
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        current = newNode;
    }
    return head;
}
Node * printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

 Node* reverse(Node*head){
        Node*temp = head;
        Node*prev = nullptr;
        while(temp != nullptr){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
}

 Node*  getKthNode(Node*temp , int k){
        k -= 1;
        while(temp != nullptr && k >0){
            k--;
            temp = temp->next;
        }
        return temp;
}

 Node* reverseKGroup(Node* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 1) return head;
        Node* temp = head;
        Node* nextNode = nullptr;
        Node* prevNode = nullptr;
        while(temp != NULL){
            Node* kthNode = getKthNode(temp,k);
            if(kthNode == nullptr){
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = nullptr;
            Node* newHead = reverse(temp);
            if(temp == head){
                head = newHead;
            }else{
                prevNode->next = newHead;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
    //TC : O(N) + O(N) = O(2N)
    //SC : O(1)

int main (){
    vector<int> arr = {1, 2, 3, 4, 5, 6 ,7 , 8 , 9 ,10};
    //Ouput : 3->2->1->6->5->4->9->8->7->10
    Node* head = convetToLL(arr);
    head = reverseKGroup(head,3);
    printLL(head);
   


};
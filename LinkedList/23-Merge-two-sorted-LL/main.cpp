#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
};
Node* convertToLL(vector<int>&arr){
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

Node* bruteForce(Node* l1 , Node* l2){
    //Take an array
    //Store l1 , l2
    //Sort
    //Create LL
    //Return head;
    vector<int> arr;
    Node* temp = l1;

    while(temp != NULL){ //O (N)
        arr.push_back(temp->data);
        temp = temp->next;
    }
    temp = l2;
    while(temp != NULL){  //O (N)
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());  //O (NLogN)
    Node* head = convertToLL(arr); //O(N)
    return head;
    // SC : O(N) + O(N)

}
int main(){
    vector<int> list1 = {2,4,8,10};
    vector<int> list2 = {1,3,4,6,11,14};
    Node* head1 = convertToLL(list1);
    Node* head2 = convertToLL(list2);

    Node* merged = bruteForce(head1,head2);
    printLL(merged);
}
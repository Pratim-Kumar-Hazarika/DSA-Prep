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
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

Node* bruteForce(vector<Node*> lists){
    vector<int> list;
    for(int i = 0 ; i< lists.size()  ;i++){ //O (K)
        Node*temp = lists[i];
        while(temp != NULL){
            list.push_back(temp->data); //O( N)
            temp = temp->next;
        }
    }
    sort(list.begin(), list.end()); // O(M log M) M = N * K
    Node* head = convertToLL(list); //O(M)
    return head;
    //SC : N * K + M log M + M
    //O  : O(M) ( storing all elements in array)  + O(M) ( new list) 
}
int main(){
    vector<int> list1 = {2,4,6};
    vector<int> list2 = {1,5};
    vector<int> list3 = {1,1,3,7};
    vector<int> list4 = {8};
    Node* head1 = convertToLL(list1);
    Node* head2 = convertToLL(list2);
    Node* head3 = convertToLL(list3);
    Node* head4 = convertToLL(list4);
    vector<Node*> lists ={head1,head2,head3,head4};

    Node* newNode = bruteForce(lists);
    printLL(newNode);
}
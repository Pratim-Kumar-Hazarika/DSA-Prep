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
Node* merge2Lists(Node* l1 , Node*l2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }else{
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }
    if(l1) temp->next = l1;
    else temp->next = l2;
    return dummy->next;
}
Node* optimised(vector<Node*> lists){
    Node*head = lists[0];
    for(int i = 1; i< lists.size() ; i++){
        head = merge2Lists(head, lists[i]);
    }
    return head;
    //TC : (N1+ N2) first list , second list
    //    (N1 + N2) + N3
    //    (N1+N2+N3) + N4
    /// Let's assume all list to be Size N
    //(N1+ N2) = 2N
    //(N1 + N2) + N3 = 3N
    //(N1+N2+N3) + N4 = 4N
    // N + 2N + 3N + ...KN
    // N (1 + 2 + 3.. K)
    // N * (K*K+1)/2 = N^3
    // O(1)
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

    Node* newNode = optimised(lists);
    printLL(newNode);
}
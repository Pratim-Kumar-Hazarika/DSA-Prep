#include<iostream>
#include<vector>
#include <queue>
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
Node* brute(Node*head){
    //Put all in array
    //Sort array
    //Create LL
    //return head
    vector<int> nums;
    Node*temp = head;
    while(temp != NULL){  // O(N)
        nums.push_back(temp->data);
        temp = temp->next;
    }
    sort(nums.begin(), nums.end()); // N log N
    Node* ans = convertToLL(nums); // O(N)
    return ans;
    // SC :O N 
}
Node* merge(Node* l1 , Node*l2){
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
    Node* findMiddle(Node* head){
        Node* slow = head;
        Node* fast = head->next; // add fast 1 step so that the middle stops 1 step before ex : 1->2->3->4 : middle will be 2
        while( fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* optimisedSortList(Node* head) {
        if(head == NULL  || head->next == NULL) return head;
        Node*  middle = findMiddle(head); //O(N/2)
        Node* left = head;
        Node* right = middle->next;
        middle->next = NULL;
        left = optimisedSortList(left);
        right = optimisedSortList(right);
        return merge(left,right); //O (N)
        ///TC :  recursion depth : log N
        //TC : logN x ( N + N/2)
        //SC : 1

    }
int main(){
    vector<int> list = {1,9,4,3,6};
    Node* head = convertToLL(list);
    Node* ans = optimisedSortList(head);
    printLL(ans);
}
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

vector<vector<int>> bruteForce(Node* head , int sum){
    vector<vector<int>> res;
    Node* temp1 = head;
    while(temp1 != NULL){
        Node* temp2 = temp1->next;
        while(temp2!= NULL && temp1->data + temp2->data <= sum){
            if(temp1->data + temp2->data == sum){
                res.push_back({temp1->data,temp2->data});
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }
    return res;
    //TC : O(N * N) ~O(N^2)
    //SC : O(1)
}
int main(){
    vector<int> arr ={1,2,3,4,9};
    //Total Sum = 5
    //Pairs [1,4] [2,3]
    Node *head = convertArrayToLL(arr);
    vector<vector<int>>ans = bruteForce(head, 5);
    for(auto pair : ans){
        cout <<"[" << pair[0] <<" " << pair[1] << "]" << endl;
    }
}
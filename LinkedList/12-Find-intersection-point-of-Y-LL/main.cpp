#include <iostream>  
#include <vector> 
#include <unordered_set> 
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

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* bruteForce(Node* head1, Node* head2) {
    //Create Set
    unordered_set<Node*> st;
    Node* temp = head1;

    // Store all nodes of list1 in the set
    while (temp != nullptr) {
        st.insert(temp);
        temp = temp->next;
    }

    // Loop list2 and check if any node exists in the set
    temp = head2;
    while (temp != nullptr) {
        if (st.find(temp) != st.end()) return temp;
        temp = temp->next;
    }
    // TC O(m + n)
    // O(m)
    return nullptr;
}

Node* collision(Node* t1, Node*t2 , int d){
    while(d){
        d--; //O(N2-N1)
        t2 = t2->next;
    }
    while(t1 != t2){
        t1= t1->next;  //O(N1)
        t2 = t2->next;
    }
    return t1;
}
Node* bestCase(Node*head1, Node* head2){
    //Traverse both the LL
    //If one is long one is small go to the difference point of that LL
    //Start traversing
    int n1 = 0 , n2=0;
    Node*temp = head1;
    while(temp != NULL){  //O(N1)
        n1++;
        temp = temp->next;
    }
    temp = head2;
    while(temp != NULL){  //O(N2)
        n2++;
        temp = temp->next;
    }
    if(n1 < n2){
        return collision(head1 , head2 , n2-n1);
    }else{
        return collision(head2,head1, n1-n2);
    }
    return NULL;
    // TC - O(N1) + O(N2) + O(N2-N1) + O(N1) = O(N + 2N2)
    // SC - O(1)
    
}

int main() {

    //Create intersection
    // 10 → 9 → 4 → 1 → 
    //                  ↘
    //                  8 → 4 → 5
    //                 ↗
    //        5 → 6 → 1

 // Create intersection: 8 → 4 → 5
    Node* intersection = new Node(8);
    intersection->next = new Node(4);
    intersection->next->next = new Node(5);

    // List A: 10 → 9 → 4 → 1 → 8 → 4 → 5
    Node* head1 = new Node(10);
    head1->next = new Node(9);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(1);
    head1->next->next->next->next = intersection;

    // List B: 5 → 6 → 1 → 8 → 4 → 5
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(1);
    head2->next->next->next = intersection;

    Node* result = bestCase(head1, head2);
    if (result != nullptr)
        cout << "Intersection point is " << result->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}

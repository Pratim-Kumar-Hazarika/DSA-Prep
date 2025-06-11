#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* bottom;
        Node(int val){
            data = val;
            next = nullptr;
            bottom = nullptr;
        }
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->bottom;
    }
    cout << "NULL" << endl;
}

 Node* convert( vector<int>& ans){
        if( ans.size() == 0) return NULL;
        Node* head = new Node(ans[0]);
        Node* temp = head;
        for(int i = 1; i< ans.size( ) ; i++){
            Node* newNode = new Node(ans[i]);
            temp->bottom = newNode;
            temp = temp->bottom;
        }
        return head;
        
    }
 Node *flattenBrute(Node *root) {
        vector<int> ans;
        Node*temp = root;
        while(temp != NULL){ //O(N)
            Node* t2 = temp;
            while(t2 != NULL){ //O(M)
                ans.push_back(t2->data); 
                t2 = t2->bottom;
            }
            temp = temp->next;

        }
        sort(ans.begin(), ans.end()); // XlogX : x = N X M
        Node* head = convert(ans); // O( N X M)
        return head;
        //TC : O(N X M) X 2 + X log X
        //SC : (NXM) x 2 : First time the array is holding elements , Second creating new LL for creating vertical LL 
    }

 Node* mergeLists(Node* l1 , Node* l2){
            Node* dummyNode = new Node(-1);
            Node* res = dummyNode;
            while(l1 != NULL && l2 != NULL){
                if(l1->data < l2->data){
                    res->bottom = l1;
                    res = l1;
                    l1 = l1->bottom;
                }else{
                    res->bottom = l2;
                    res = l2;
                    l2 = l2->bottom;
                }
            }
            if(l1) res->bottom = l1;
            else res->bottom = l2;
            return dummyNode->bottom;
            //O(N1 + N2)
            //O (M + N)
            //O(2M)
}
Node *flattenOptimised(Node *root) {
        if(!root || !root->next){
            return root;
        }
        Node* mergedHead = flattenOptimised(root->next);
        return mergeLists(root,mergedHead); //N X O(2M) ~ O(2NM)
        //SC -O(1)
}
int main(){
    Node* n1 = new Node(5);
    n1->bottom = new Node(7);
    n1->bottom->bottom = new Node(8);
    n1->bottom->bottom->bottom = new Node(30);

    Node* n2 = new Node(10);
    n2->bottom = new Node(20);

    Node* n3 = new Node(19);
    n3->bottom = new Node(22);
    n3->bottom->bottom = new Node(50);

    Node* n4 = new Node(28);
    n4->bottom = new Node(35);
    n4->bottom->bottom = new Node(40);
    n4->bottom->bottom->bottom = new Node(45);

    // Connect horizontal next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;



      // Flatten and print results
    cout << "Brute Force Output: ";
    Node* resultBrute = flattenBrute(n1);
    printList(resultBrute);

    // Rebuild the original list before reusing it for optimized (because brute creates a new list)
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    cout << "Optimised Output: ";
    Node* resultOptimised = flattenOptimised(n1);
    printList(resultOptimised);

    return 0;
}
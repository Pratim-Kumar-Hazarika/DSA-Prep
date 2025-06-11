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
            //N * (N1 + N2)
}
Node *flattenOptimised(Node *root) {
        if(!root || !root->next){
            return root;
        }
        Node* mergedHead = flattenOptimised(root->next);
        return mergeLists(root,mergedHead);
}
int main(){

}
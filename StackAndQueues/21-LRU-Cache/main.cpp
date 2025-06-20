#include<iostream>
using namespace std;

class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
    Node(int _key, int _val){
        key = _key;
        value = _val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {

    Node *head ;
    Node *tail;
    int cap;
    unordered_map<int, Node*> mpp;
public:
    LRUCache(int _capacity) {
        cap = _capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode){
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
    }
    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;

    }
    int get(int _key) {
        if(mpp.find(_key) != mpp.end()){
            Node* res = mpp[_key];
            int val = res->value;
            deleteNode(res);
            addNode(res);
            return val;
        }
        return -1;
    }
    
    void put(int _key, int _value) {
        if(mpp.find(_key) != mpp.end()){
            Node* exists = mpp[_key];
            exists->value = _value;
            deleteNode(exists);
            addNode(exists);
            return;
        }
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(_key, _value);
        addNode(newNode);
        mpp[_key] = head->next;
    }
};

//TC : O(1)
//SC : O(capacity)
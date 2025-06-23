#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
  public:
    int key;
    int value;
    int cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _val){
        key = _key;
        value = _val;
        cnt = 0;
        next = NULL;
        prev = NULL;
    }
};

class List{
    public:
        int size;
        Node* head;
        Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node){
        Node *temp = node->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    void removeNode(Node* node){
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};
class LFUCache{
    unordered_map<int,Node*> keyMap;
    unordered_map<int,List*> freqMap;
    int cursize;
    int maxSizeCache;
    int minFreq;
    public:
        LFUCache(int capacity){
            maxSizeCache = capacity;
            cursize = 0;
            minFreq = 0;
        }
    void updateFreqMap(Node* node){
        keyMap.erase(node->key);
        freqMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqMap[node->cnt]->size == 0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqMap.find(node->cnt +1) != freqMap.end()){
            nextHigherFreqList = freqMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqMap[node->cnt] = nextHigherFreqList;
        keyMap[node->key] = node;
    }
    int get(int key){
        if(keyMap.find(key) != keyMap.end()){
            Node *node = keyMap[key];
            int val = node->value;
            updateFreqMap(node);
            return val;
        }
        return -1;
    }
    void put(int key, int value){
        if(maxSizeCache == 0){
            return;
        }
        if(keyMap.find(key) != keyMap.end()){
            Node* node = keyMap[key];
            node->value = value;
            updateFreqMap(node);
        }else{
            if(maxSizeCache == cursize){
                List* list = freqMap[minFreq];
                keyMap.erase(list->tail->prev->key);
                freqMap[minFreq]->removeNode(list->tail->prev);
                cursize--;
            }
            cursize++;
            minFreq = 1;
            List* list = new List();
            if(freqMap.find(minFreq) != freqMap.end()){
                list = freqMap[minFreq];
            }
            Node * node = new Node(key,value);
            list->addFront(node);
            keyMap[key] = node;
            freqMap[minFreq] = list;
        }

    }
};
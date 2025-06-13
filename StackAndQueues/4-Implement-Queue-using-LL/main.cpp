#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int val){
            data = val;
            next = nullptr;
        }
};

class Queue {
    public:
        int size;
        Node* start;
        Node* end;
        Queue(){
            size = -1;
            start = NULL;
            end = NULL;
        }

    void push(int val){
        Node* newNode = new Node(val);
        if(start == NULL){
            start = end = newNode;
        }else{
            end->next = newNode;
            end = end->next;
        }
        size++;
    }

    void pop(){
        Node* temp = start;
        start = start->next;
        delete temp;
        if(start == NULL){
            end = NULL;
        }
        size--;
    }

    int maxSize(){
        return size+1;
    }
    int top(){
        return start->data;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.maxSize() << endl;
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    cout << q.maxSize() << endl;
    return 0;
}
#include<iostream>
using namespace std;

//All operations take O(1)
class Node {
    public:
    int data;
    Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
};
class Stack {
    public:
    int size;
    Node*top;
       Stack(){
        size = -1;
        top = NULL;
    };

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size+=1;
    }
    void pop(){
        Node* temp = top;
        top = top->next;
        delete temp;
        size -=1;
    }
    int topElement (){
        return top->data;
    }
    int maxSize (){
        return size +1;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(5);
    s.push(9);
    cout << s.topElement() << endl;
    s.pop();
    cout << s.topElement() << endl;
    return 0;

}
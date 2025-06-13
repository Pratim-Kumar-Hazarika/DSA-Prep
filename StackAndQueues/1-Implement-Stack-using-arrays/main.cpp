#include<iostream>
using namespace std;

class Stack {
    int st[10]; //TC - O(10) not good
    int top;
    public: 
        Stack(){
            top = -1;
        }
    int topElement(){ //O(1)
        if(top == -1){
            return -1;
        }
        return st[top];
    }
    int size(){  //O(1)
        return top+1;
    }
    int pop(){  //O(1)
       return st[top--]; 
    }
    void push(int val){  //O(1)
        if (top == 9) {
            cout << "Stack overflow!" << endl;
            return;
        }
        st[++top] = val;

    }
};

int main(){

    Stack s;
    s.push(1);
    s.push(4);
   cout << s.topElement() << endl;
   cout <<  s.size() << endl;
    return 0;
}
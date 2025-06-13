#include<iostream>
#include<stack>
using namespace std;

class Queue {
public:
stack<int> s1, s2;
    Queue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()){
            throw runtime_error("Queue is empty");
        }
        int n = s2.top();
        s2.pop();
        return n;
    }
    
    int top() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
           if(s2.empty()){
            throw runtime_error("Queue is empty");
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(7);
    q.push(2);
    q.push(9);
    cout << q.top() << endl; //1
    cout << q.pop() << endl; //1
    cout << q.top() << endl; //7
    return 0;
}

#include<iostream>
#include<queue>
using namespace std;


class Stack {
    queue<int> q;

public:
    Stack() {
        
    }
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i = 0 ; i< s ; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
    int size(){
        return q.size();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(4);
    s.push(7);
    s.push(9);
    cout << s.top() << endl;
    cout <<  s.size() << endl;
    return 0;
}
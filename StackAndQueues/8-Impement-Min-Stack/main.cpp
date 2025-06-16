#include<iostream>
#include<stack>
using namespace std;

class MinStackBrute {
    //TC : O(1)
    //SC : O(2XN) pair of DS is stored to get the getMin function running
    stack<pair<int,int>> st;
public:

    MinStackBrute() {
        
    }
    
    void push(int val) {
        int mini;
        if(st.empty()){
            mini = val;
        }else{
            mini = min(val,st.top().second);
        }
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
int main(){
    MinStackBrute st;
    st.push(5);
    st.push(3);
    st.push(7);
    cout << st.getMin() << endl; // 3
    st.pop();
    cout << st.getMin() << endl; // 3
    st.pop();
    cout << st.getMin() << endl; // 5
    cout << st.top() << endl;    // 5

}
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


class MinStackOptimised {
    //Trick : 2 x val - prev_mini = newVal;
    stack<long long > st;
    long long mini = INT_MAX;
    public:
        MinStackOptimised(){

        };

        void push(int val){
            long long x = val;
            if(st.empty()){
                mini = x;
                st.push(x);
            }else{
                if(val < mini){
                    st.push(2*val*1LL-mini);
                    mini = val;
                }else{
                    st.push(val);
                }
            }
        }
        void pop(){
            long long el = st.top();
            st.pop();
            if(el < mini){
                mini = 2*mini - el;
            }
        };
        int top(){
            if(st.empty())return -1;
            long long el = st.top();
            if(el < mini){
                return mini;
            } return el;
        };
        int getMin(){
            return mini;
        }

};

int main(){
    MinStackOptimised st;
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
#include<iostream>
#include<stack>
using namespace std;


bool isValid(string s){
    stack<char> st;
    for(auto it : s){
        if(it == '(' || it =='[' || it == '{'){
            st.push(it);
        }else{
            if(st.size() == 0) return false;
            char ch = st.top();
            st.pop();

            if( (ch == '(' && it ==')') || (ch == '[' && it ==']') || (ch =='{' && it == '}')){
                continue;
            }else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    string s = "()[]{}";
    bool ans = isValid(s);
    cout << ans << endl;
}
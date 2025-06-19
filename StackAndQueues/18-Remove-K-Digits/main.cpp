#include<iostream>
#include<stack>
#include<string>
using namespace std;

 string removeKdigits(string s, int k) {
        stack<char> st;
        int n = s.size();
        string res ="";
        for(int i = 0 ; i < n ; i++){ //TC O(N)
            while(!st.empty() && k >0 && st.top() > s[i]){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0 && !st.empty()){ //TC O(K)
            st.pop();
            k--;
        }
        while(!st.empty()){ //TC O(N)
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end()); //TC O(N)
        while(!res.empty() && res[0] == '0'){
            res.erase(res.begin()); //TC O(N)
        }
        return res.empty() ? "0" : res;
        //TC : O(3N) + O(K)
        //SC : O(N) + O(N)
 };

int main(){
    string res =removeKdigits("10200", 1);
    cout << res << endl;
    return 0;
}
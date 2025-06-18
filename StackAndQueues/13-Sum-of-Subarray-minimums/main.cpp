#include<iostream>
#include<stack>
using namespace std;


int brute(vector<int>& arr){
    int  n = arr.size();
    if( n == 1) return arr[0];
    int sum = 0;
    int mod = 1e9+7;
    for(int i = 0 ; i< n ; i++){
        int mini = arr[i];
        for(int j = i ; j < n ; j++){
            mini = min(mini, arr[j]);
            sum = (mini+sum) % mod;
        }
        
    }
    return sum;
    //TC :N^2
    //SC :O(1)
}
vector<int> findNse(vector<int>& arr){
    int n  = arr.size();
    vector<int> nse(n , -1);
    stack<int> st;
    for(int i = n-1 ;i >=0 ; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPse(vector<int>& arr){
    int n  = arr.size();
    vector<int> pse(n , -1);
    stack<int> st;
    for(int i =0 ; i< n ; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        pse[i] =  st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
int optimise(vector<int>& arr){
    int  n = arr.size();
    if(n == 1) return arr[0];
    vector<int> nse = findNse(arr);// TC : O(2N) SC : O(2N)
    vector<int> pse = findPse(arr);// TC : O(2N) SC : O(2N)
    int total = 0;
    int mod = (int)(1e9+7);
    for(int i = 0 ; i< n ; i++){ //TC :O(N)
        int left = i - pse[i];
        int right = nse[i]  - i;
        total = (total +(left * right * 1LL * arr[i]) % mod )%mod;
    }
    return total;
    //TC : O(5N)
    //TC : O(5N)
}
int main(){
    vector<int> arr = {3,1,2,4};
    //output = 17
    int ans = brute(arr);
    cout << ans << endl;
}
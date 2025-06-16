#include<iostream>
#include<stack>
using namespace std;


vector<int> brute(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n,-1);
    //TC : O(N^2)
    //SC :O(N)
    for(int i = 0 ; i < n  ; i++){
        for(int j = i -1 ; j >=0 ; j--){
            if(nums[j] < nums[i]){
                ans[i] = nums[j];
                break;
            }
        }
    }
    return ans;
}
vector<int> optimise(vector<int>& nums){
     int n = nums.size();
     vector<int> ans(n,-1);
     stack<int> st;
     for(int i = 0  ; i < n ; i++){//O(N)
        while(!st.empty() && st.top() >= nums[i]){
            st.pop(); //O(N)
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
     }
     return ans;
     //TC : O(2N)
     //SC : O(N) + O(N)

}
int main(){
    vector<int> nums = {4,5,2,10,8};
    //Output : {-1,4,-1,2,2}
    vector<int> ans = optimise(nums);
    for(int num : ans){
        cout << num << endl;
    }
    return 0;
}
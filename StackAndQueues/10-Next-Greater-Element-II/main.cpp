#include<iostream>
#include<stack>
using namespace std;

vector<int> nextGreaterElementsBrute(vector<int>& nums) {
    int N = nums.size();
    vector<int> nge(N , -1);
    //TC O(N^2)
    //SC O(N)
    for(int i = 0 ; i< N ; i++){ //O (N)
        for(int j = i+1 ; j < i + N ; j++){ //O(N)
            int ind = j % N ;
            if( nums[ind] > nums[i]){
                nge[i] = nums[ind];
                break;
            }
        }
    }
    return nge;
}
vector<int> nextGreaterElementsOptmised(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n , -1);
        stack<int> st;
        for(int i = 2*n-1 ; i >=0 ; i--){ //TC O(2N)
                 int idx = i % n;
            while(!st.empty() && st.top() <= nums[idx]){
                st.pop(); //TC O(2N)
            }
            if(!st.empty()){
                nge[idx] = st.top();
            }
            st.push(nums[idx]); //TC O(2N)
        }
        //TC :O(4N)
        //SC :O(2N) stack size + O(N) return the ans
        return nge;
    }
int main(){
    vector<int> nums = {1,2,1};
    ///Output: [2,-1,2]
    vector<int> ans = nextGreaterElementsOptmised(nums);
    for(int num : ans){
        cout << num << endl;
    }
    return 0;
}
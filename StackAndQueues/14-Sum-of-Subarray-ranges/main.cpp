#include<iostream>
#include<stack>
using namespace std;


 long long subArrayRangesBrute(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int largest = nums[i], smallest = nums[i];
            for (int j = i + 1; j < n; j++) {
                largest = max(largest, nums[j]);
                smallest = min(smallest, nums[j]);
                sum += (long long)(largest - smallest);
            }
        }
        //TC : O (N^2)
        return sum;
    }

class Solution {
public:
    vector<int> findPge(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = 0 ; i< n ; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
             st.push(i);
        }
        return ans;
    }
    vector<int> findPse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findNge(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findNse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total += left * right * 1LL * arr[i];
        }
        return total;
    }
    long long sumMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge=  findNge(arr);
        vector<int> pge= findPge(arr);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;
            total += left * right * 1LL * arr[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& arr) {
        if (arr.size() == 1) return 0;

        return sumMax(arr) - sumMin(arr);
    }
};
int main(){
    vector<int> nums = {1,2,3};
    ///Output : 4
    long long ans = subArrayRangesBrute(nums);
    Solution s;
    long long ans2=  s.subArrayRanges(nums);
    cout << ans << endl;
    cout << ans2 << endl;
    return 0;
}
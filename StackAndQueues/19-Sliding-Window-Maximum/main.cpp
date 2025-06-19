#include<iostream>
#include<stack>
using namespace std;



vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> list;
        int n = nums.size();
        for(int i = 0 ; i< n - k + 1 ; i++){ //TC :O(N- K)
            int maxi = nums[i];
            for(int j = i +1; j < i + k ; j++){ //TC : O(K)
                maxi = max(maxi, nums[j]);
            }
            list.push_back(maxi);
        }
        return list;
        //TC : O(N-K) x O(K)
        //TC : O(N-K)
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    //out  [3,3,5,5,6,7]
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums,k);
    for(int num : ans){
        
        cout << num << " ";
    }
    return 0;
};

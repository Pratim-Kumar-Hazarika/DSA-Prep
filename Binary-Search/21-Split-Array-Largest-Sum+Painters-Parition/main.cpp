#include <iostream>
#include <vector>
#include <numeric>  
#include <climits>

using namespace std;

    int possible(int mid, vector<int>& nums){
        int n = nums.size();
        int cnt=1;
        int cap=0;
        for(int i = 0 ; i < n ; i++){
            if(cap + nums[i] <= mid){
                cap+= nums[i];
            }else{
                cnt++;
                cap = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low <= high){
            int mid = (low + high)/2;
            int x = possible(mid,nums);
            if(x > k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }

int main(){
    vector<int> num =  {12, 34, 67, 90};
    int k = 2;
    cout << splitArray(num,k) <<endl;
}
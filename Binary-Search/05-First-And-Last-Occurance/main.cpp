#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


//Sol 1 : Linear Search O(N)
//Sol 2 : Lower Bound + Upper Bound 2*log base 2^n . Sc : O(1)
///Edge cases lb(x) === n || arr[lb] != x


class Solution {
public:
    int firstOccurance(vector<int>& nums, int target){
        int n = nums.size();
        int first = -1;
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid-1;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return first;

    }

     int lastOccurance(vector<int>& nums, int target){
        int n = nums.size();
        int last = -1;
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid+1;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return last;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurance(nums,target);
        if(first == -1) return  {-1,-1};
        int last = lastOccurance(nums,target);
        return {first,last};
    }
};


int main() {
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};

    auto res1 = sol.searchRange(nums, 8);
    cout << "[" << res1[0] << "," << res1[1] << "]" << endl; // [3,4]

    auto res2 = sol.searchRange(nums, 6);
    cout << "[" << res2[0] << "," << res2[1] << "]" << endl; // [-1,-1]

    auto res3 = sol.searchRange(nums, 5);
    cout << "[" << res3[0] << "," << res3[1] << "]" << endl; // [0,0]

    auto res4 = sol.searchRange(nums, 10);
    cout << "[" << res4[0] << "," << res4[1] << "]" << endl; // [5,5]

    return 0;
}

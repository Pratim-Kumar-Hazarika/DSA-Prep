#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low + high) / 2;

            // if subarray is sorted
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }

            // left half is sorted
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            // right half is sorted
            else{
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "Array: ";
    for(int x : nums) cout << x << " ";
    cout << endl;

    int result = sol.findMin(nums);
    cout << "Minimum element is: " << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;

            // Left half is sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
            // Right half is sorted
            else {
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target;

    cout << "Enter target: ";
    cin >> target;

    int result = sol.search(nums, target);
    if(result != -1)
        cout << "Target found at index " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}

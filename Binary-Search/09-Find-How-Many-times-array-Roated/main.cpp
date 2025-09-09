#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int findRotation(vector<int> &nums){
    int n = nums.size();
    int ans = -1;
    int index = -1;
    int low = 0 , high = n-1;

    while(low <= high){
        int mid = (low + high)/2;

        // If current segment is sorted
        if(nums[low] <= nums[high]){
            if(ans < nums[high]){   // check high (max of sorted segment)
                ans = nums[high];
                index = high;
            }
            break;
        }

        // Left half is sorted
        if(nums[low] <= nums[mid]){
            if(ans < nums[mid]){
                ans = nums[mid];
                index = mid;
            }
            low = mid+1;
        }
        // Right half is sorted
        else{
            if(ans < nums[high]){
                ans = nums[high];
                index = high;
            }
            high = mid-1;
        }
    }

    return index;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "Array: ";
    for(int x : nums) cout << x << " ";
    cout << endl;

    int idx = findRotation(nums);
    cout << "Rotation index (max element) = " << idx << endl;
    cout << "Max element = " << nums[idx] << endl;

    return 0;
}

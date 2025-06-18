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
int main(){
    vector<int> nums = {1,2,3};
    ///Output : 4
    long long ans = subArrayRangesBrute(nums);
    cout << ans << endl;
    return 0;
}
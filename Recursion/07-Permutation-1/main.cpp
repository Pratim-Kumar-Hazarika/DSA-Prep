#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    void func(vector<int> &ds, vector<int>& nums, vector<vector<int>> &ans, vector<int> &freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;

                func(ds, nums, ans, freq);

                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> ds;
        vector<int> freq(n, 0);
        func(ds, nums, ans, freq);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.permute(nums);

    cout << "Permutations:\n";
    for (const auto& perm : result) {
        cout << "[ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

void func(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int> &ds) {
    ans.push_back(ds);
    for(int i = ind ; i < nums.size() ; i++) {
        if(i > ind && nums[i] == nums[i-1]) continue; // skip duplicates
        ds.push_back(nums[i]);
        func(i + 1, nums, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    func(0, nums, ans, ds);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 2, 4};

    vector<vector<int>> result = subsetsWithDup(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

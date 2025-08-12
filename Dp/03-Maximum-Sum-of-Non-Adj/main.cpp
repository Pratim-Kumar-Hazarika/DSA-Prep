#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Recursion + Memoization
    int sol(int ind , vector<int>& a, vector<int>& dp) {
        if (ind == 0) return a[ind];
        if (ind < 0) return 0;
        if (dp[ind] != -1) return dp[ind];
        int pick = a[ind] + sol(ind - 2, a, dp);
        int notpick = sol(ind - 1, a, dp);
        return dp[ind] = max(pick, notpick);
    }

    int robMemo(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return sol(n - 1, nums, dp);
            //TC : 2^n
    }

    // Tabulation
    int robTab(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n + 1, -1);
        dp[0] = a[0];
        for (int i = 1; i < n; i++) {
            int take = a[i];
            if (i > 1) take += dp[i - 2];
            int nontake = dp[i - 1];
            dp[i] = max(take, nontake);
        }
        return dp[n - 1];
          //TC : O(N)
        //SC : O(N) + O(N)
    }

    // Space Optimized
    int robOptimised(vector<int>& a) {
        int n = a.size();
        int prev = a[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = a[i];
            if (i > 1) take += prev2;
            int nontake = prev;
            int curi = max(take, nontake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
        //TC : O(N)
        //SC : O(1)
    }
};

int main() {
    Solution obj;
    vector<int> houses = {2, 7, 9, 3, 1};

    cout << "Recursion + Memoization: " << obj.robMemo(houses) << endl;
    cout << "Tabulation: " << obj.robTab(houses) << endl;
    cout << "Space Optimised: " << obj.robOptimised(houses) << endl;

    return 0;
}

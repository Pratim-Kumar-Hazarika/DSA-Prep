#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
  public:
  int f(int ind,vector<int>&heights ,vector<int>&dp){
      if(ind == 0) return 0;
      if(dp[ind] != -1) return dp[ind];
      int left = f(ind-1, heights,dp) + abs(heights[ind] - heights[ind-1]);
      int right = INT_MAX;
      if(ind > 1) right = f(ind-2, heights,dp) + abs(heights[ind] - heights[ind-2]);
      return dp[ind]= min(left,right);
  }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,-1);
        return f(n-1,height,dp);
    }
    //SC : O(N) Stack Space +O(N)
};

//Tabulation (Bottom - Up)
int minCostTabulation(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,0);
        dp[0] = 0;
        for(int i =1 ; i< n ; i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(ss,fs);
        }
        
        return dp[n-1];

            //SC : O(N) Stack Space removed +O(N) = O(N)
}



int minCostSpaceOptimises(vector<int>& height) {
        // Code here
        int n = height.size();
        int prev =0;
        int prev2 = 0;
        for(int i =1 ; i< n ; i++){
            int fs = prev + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = prev2 + abs(height[i] - height[i-2]);
            }
           int curi = min(ss,fs);
           prev2 = prev;
           prev = curi;
        }
        
        return prev;
       //SC :O(1)
}

//Note :if there is ind - 1 , ind - 2 there will be always space optimization

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};

    Solution sol;
    cout << "Recursive + Memoization: " << sol.minCost(heights) << endl;
    cout << "Tabulation: " << minCostTabulation(heights) << endl;
    cout << "Space Optimised: " << minCostSpaceOptimises(heights) << endl;

    return 0;
}

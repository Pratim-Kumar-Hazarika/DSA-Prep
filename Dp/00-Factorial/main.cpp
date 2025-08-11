#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Top Down
int fibonnaci(int n , vector<int>&dp){
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
        return dp[n] = fibonnaci(n-1,dp) + fibonnaci(n-2,dp);
        //TC : O(N)
        //SC : O(N) + O(N)
}
//Tabulation ( Bottom - Up)
int main(){
     int n = 5;
     vector<int> dp(n+1,-1);
     cout << fibonnaci(n,dp);

     int prev2 = 0;
     int prev1 = 1;
     for(int  i =2 ; i<= n ; i++){
        int curi = prev1+ prev2;
        prev2 = prev1;
        prev1 = curi;
     }
    cout << prev1;
}
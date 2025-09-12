#include <iostream>
#include <vector>
#include <numeric>  
#include <climits>

using namespace std;
    int upperBound(vector<int> &mat,int x , int n){
        int x1= mat.size();
        int low = 0 , high = x1-1;
        int ans = x1;
        while(low <= high){
            int mid = (low + high)/2;
            if(mat[mid] > x){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int  blackBox(vector<vector<int>> &mat, int x, int n , int m){
            int cnt = 0;
            for(int i = 0 ; i< n ; i++){
                cnt+= upperBound(mat[i],x,m);
            }
            return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int low = INT_MAX, high = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i< n ; i++){
            low = min(low,mat[i][0]);
            high = max(high,mat[i][m-1]);
        }
        int req = (n*m)/2;
        
        while(low <= high){
                int mid = (low + high)/2;
                int cntNums = blackBox(mat,mid,n,m);
                if(cntNums<= req){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
        }
        return low;
        
    }


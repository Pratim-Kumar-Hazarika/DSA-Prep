#include <iostream>
#include <vector>
#include <numeric>  
#include <climits>

using namespace std;

int lowerBound(vector<int>&arr , int x){
        int n = arr.size();
        int low = 0 , high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid]>=x){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;

    }
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int cnt_max = 0;
        int index = 0;
        int m = mat[0].size();
        for(int i = 0 ; i< n ; i++){
            vector<int> row = mat[i];
            sort(row.begin(), row.end());
            int total_cnt = m - lowerBound(row,1);
            if(total_cnt > cnt_max){
                cnt_max= total_cnt;
                index = i;
            }
        }

        return {index,cnt_max};
    }
int main(){
    
}
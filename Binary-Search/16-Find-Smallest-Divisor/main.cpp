#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


    bool isPossible(int divisor,vector<int>& nums,int x){
        int n = nums.size();
        long long ans = 0;

        for(int i = 0 ; i< n ; i++){
            ans += ceil((double)(nums[i])/(double)(divisor));
        }
         if(ans <=x){
            return true;
         }else{
            return false;
         }

       
    }
    int smallestDivisor(vector<int>& nums, int x) {
        int n = nums.size();
        if(n > x) return -1;
        int low = 1 , high = *max_element(nums.begin(),nums.end());


        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(mid,nums,x)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }

    int main(){
        vector<int>nums = {1,2,5,9};
        int threshold = 6;
        cout << smallestDivisor(nums,threshold) << endl;

    }

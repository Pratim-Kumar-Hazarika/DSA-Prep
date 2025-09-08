
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


int lowerBound(vector<int>& nums, int x){
    int n = nums.size();
    int ans = n;
    int low = 0 , high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] >= x){
            //maybe an ans
            ans = nums[mid];
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}


int upperBound(vector<int>& nums, int x){
    int n = nums.size();
    int ans = n;
    int low = 0 , high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] > x){ /////This changes
            //maybe an ans
            ans = nums[mid];
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}


int main(){
     vector<int> nums={-1,0,3,5,6,8,9,12};
     int x = 7;
     //Lower  bound >= x : 5
     int lowerBoundAns = lowerBound(nums,x);
     cout << lowerBoundAns << endl;


     //Upper bound  > x

     int upperBoundAns = upperBound(nums,x);
     cout << upperBoundAns << endl;


     //Stdl C++
     auto lb = lower_bound(nums.begin(), nums.end(),x);
     cout << "Lb : " << *lb << endl;

     auto ub = upper_bound(nums.begin(), nums.end(),x);
     cout << "ub : " << *lb << endl;
}
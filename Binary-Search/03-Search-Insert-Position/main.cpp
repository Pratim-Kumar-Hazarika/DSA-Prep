
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
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr ={1 ,2,4,7};
    int x = 6;
    //On index 3 
    //lower bound >=
    //What is x = 2 ? Then insert it after 2 . At index 2 ( Lower Bound >=)
    auto lb = lower_bound(arr.begin(),arr.end(),x); 
    cout << *lb << endl; ///This returns 7 index of 7 is 3 so 6 will go there.

    int ans = lowerBound(arr,x);
    cout << "Index Pos:" << ans << endl;
}
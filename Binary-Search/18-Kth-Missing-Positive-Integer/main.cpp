#include <iostream>
#include <vector>
#include <numeric>  
#include <climits>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0 , high = n-1;

        while(low <= high){
            int mid = (low + high)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return high + k +1;
        // 1 2* 3* 4* 5 6 7 
        ///arr[high] = 7     missing =  3  ( 1 5 6) // more = k- missing = 5-3 =2
        ///missing = arr[high] -(high +1);
        //more = k - missing
        //arr[high] + more
        //arr[high] + k - missing
        //arr[high] + k - (arr[high]-high-1)
        //arr[high]+k - arr[high]+high+1
        //k+high+1
}

int main(){
    vector<int>arr = {2,3,4,7,11};
    int k = 5;
    cout << findKthPositive(arr,k) << endl;
}

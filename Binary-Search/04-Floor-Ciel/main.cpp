
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//Floor : largest no in array <=x
//Ceil  : smallest no in array >=x ( Lower Bound )

int floorBound(vector<int>& arr, int x){
    int n = arr.size();
    int ans = -1;
    int low = 0 , high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] <=x){
            ans = arr[mid];
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr ={10,20,30,40,50};
    int x = 25;
    //Floor : 20  x <=20
    //Ceil  : 30  x >=30

    int ans = floorBound(arr,x);
    cout << "Floor " <<  ans << endl;

    auto ceil = lower_bound(arr.begin(), arr.end(),x);
    cout << "Ceil " << *ceil << endl;
} 
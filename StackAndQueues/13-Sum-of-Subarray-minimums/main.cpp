#include<iostream>
#include<stack>
using namespace std;


int brute(vector<int>& arr){
    int  n = arr.size();
    if( n == 1) return arr[0];
    int sum = 0;
    int mod = 1e9+7;
    for(int i = 0 ; i< n ; i++){
        int mini = arr[i];
        for(int j = i ; j < n ; j++){
            mini = min(mini, arr[j]);
            sum = (mini+sum) % mod;
        }
    }
    return sum;
    //TC :N^2
    //SC :O(1)
}
int main(){
    vector<int> arr = {3,1,2,4};
    //output = 17
    int ans = brute(arr);
    cout << ans << endl;
}
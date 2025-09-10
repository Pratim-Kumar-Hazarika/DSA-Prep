#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int squarRoot(int n){
    int low = 1 , high = n;
    long long ans = 1;
    while(low <=high){
        long long mid = (low + high)/2;
        long long sqroot = (mid * mid);
        if(sqroot <= n){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return (int)(ans);

}

int main(){
    int n = 25;
    int ans =  squarRoot(n);
    cout << ans << endl;
}
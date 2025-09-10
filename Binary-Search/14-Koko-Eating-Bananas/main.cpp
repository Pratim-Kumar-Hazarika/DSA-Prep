#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


    long long func(vector<int>& piles, int hourly){
        long long totalH = 0;
        for(int num :piles ){
            totalH += (num+hourly-1LL)/hourly;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin(),piles.end());

        while(low <= high){
            int mid = (low+high)/2;
            long long totalH = func(piles,mid);
            if(totalH <= h){
                high = mid-1;
           }else{
            low = mid+1;
           }
        }

        return low;
    }


int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << minEatingSpeed(piles,h) << endl;
}
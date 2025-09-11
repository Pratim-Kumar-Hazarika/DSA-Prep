#include <iostream>
#include <vector>
#include <numeric>  
#include <climits>

using namespace std;


    
    bool canPossible(int mid,vector<int> &stalls, int k){
        int n =stalls.size();
        int cnt = 1, last = stalls[0];
        
        for(int i = 1 ; i < n ; i++){
            if(stalls[i] - last >=mid){
                cnt++;
                last= stalls[i];
            }
            if(cnt>=k) return true;
         
        } 
       
        return false;
        
    };
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int low = 1, high =  stalls[n-1] - stalls[0];
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(canPossible(mid,stalls,k) == true){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high;
    
        
    }
    int main(){
        vector<int> arr={1, 2, 4, 8, 9};
        int k = 3;
        cout <<  aggressiveCows(arr,k) << endl;
    }
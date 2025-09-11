#include <iostream>
#include <vector>
#include <numeric>  
#include <climits>

using namespace std;


int possible(vector<int> &arr, int pages){
        int n = arr.size();
        int cnt = 1;
        int cap = 0;
        for(int i = 0 ;i< n ; i++){
            if(arr[i] + cap <=pages){
                
                cap+= arr[i];
            }else{
                cnt++;
                cap = arr[i];
            }
        }
        return cnt;
};

int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n)return -1;
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
            
        while(low <= high){
            int mid = (low + high)/2;
            int noOfStudents = possible(arr,mid);
            if(noOfStudents > k){
                low = mid+1;
            }else{
                high = mid-1;
            }
            
        }    
        return low;
    };

int main(){
    vector<int> num =  {12, 34, 67, 90};
    int k = 2;
    cout << findPages(num,k) <<endl;
}
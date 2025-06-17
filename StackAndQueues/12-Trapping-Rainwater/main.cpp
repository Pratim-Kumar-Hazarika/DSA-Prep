#include<iostream>
#include<stack>
using namespace std;



 int trapBrute(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prefix(n,-1);
        vector<int> suffix(n,-1);
        prefix[0] = height[0];
        for(int i = 1 ; i< n ; i++){ //TC O(N)
            prefix[i]  = max(prefix[i-1], height[i]);
        }
        suffix[n-1] = height[n-1];
        for(int i = n-2 ; i>=0 ; i--){ //TC O(N)
            suffix[i] = max(suffix[i+1] , height[i]);
        }

        int total = 0;
        for(int i = 0 ;i< n ; i++){ //TC O(N)
            int preffixMax = prefix[i];
            int suffixMax = suffix[i];
            if(height[i] < preffixMax && height[i] < suffixMax){
                total += min(preffixMax,suffixMax) - height[i];
            }
        }
        return total;
        //TC : O(3N)
        //SC : P(2N)
    }

 int trapOptmises(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int left = 0 , right = n-1;
        int leftMax = 0 , rightMax = 0, total = 0;
        while(left < right){
            if(arr[left] <= arr[right]){
                if(leftMax > arr[left]){
                    total+= leftMax - arr[left];
                }else{
                    leftMax = arr[left];
                }
                left++;
            }else{
                if(rightMax > arr[right]){
                    total+= rightMax - arr[right];                    
                }else{
                    rightMax = arr[right];
                }
                right--;
            }
        }

        return total;
        //TC : O(N)
        //SC : O(1)
      
    }
int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    //output 6;
    int ans = trapBrute(height);
    cout << ans << endl;
    return 0;
}
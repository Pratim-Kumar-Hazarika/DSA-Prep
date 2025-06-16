#include<iostream>
#include<stack>
using namespace std;

vector<int> nextGreaterElementsBrute(vector<int>& nums) {
    int N = nums.size();
    vector<int> nge(N , -1);
    //TC O(N^2)
    //SC O(N)
    for(int i = 0 ; i< N ; i++){ //O (N)
        for(int j = i+1 ; j < i + N ; j++){ //O(N)
            int ind = j % N ;
            if( nums[ind] > nums[i]){
                nge[i] = nums[ind];
                break;
            }
        }
    }
    return nge;
}
int main(){
    vector<int> nums = {1,2,1};
    ///Output: [2,-1,2]
    vector<int> ans = nextGreaterElementsBrute(nums);
    for(int num : ans){
        cout << num << endl;
    }
    return 0;
}
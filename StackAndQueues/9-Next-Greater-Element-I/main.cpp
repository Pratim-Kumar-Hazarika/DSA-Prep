#include<iostream>
#include<stack>
using namespace std;

vector<int> nextGreaterElementBrute(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size();
    vector<int> nge(n1,-1);
    int n2 = nums2.size();
    //TC : O N^2
    //SC : O(n1)
    for(int i = 0 ; i< n1 ; i++){
        for(int j = 0 ; j < n2 ; j ++){
            if(nums1[i] == nums2[j]){
                for(int k = j +1 ; k < n2 ; k++){
                    if(nums2[k] > nums2[j]){
                        nge[i] = nums2[k];
                        break;
                    }
                }
            }
        }
    }
    return nge;

}
int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    //Output: [-1,3,-1]
    vector<int> ans = nextGreaterElementBrute(nums1, nums2);
    for(auto it : ans){
        cout <<  it  << endl;
    }
   
    return 0;
}
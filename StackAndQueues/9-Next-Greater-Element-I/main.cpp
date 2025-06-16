#include<iostream>
#include<stack>
using namespace std;

vector<int> nextGreaterElementBrute(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size();
    vector<int> nge(n1,-1);
    int n2 = nums2.size();
    //TC : O N^2
    //SC : O(N1)
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

 vector<int> nextGreaterElementOptimises(vector<int>& nums1, vector<int>& nums2) {
        int maxElement = *max_element(nums2.begin(), nums2.end());
        vector<int> nge(maxElement+1, -1);
        stack<int> st;
        for(int i = nums2.size()-1 ; i>= 0 ; i--){
            int num = nums2[i];
            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            if(!st.empty()){
                nge[num] = st.top();
            }
            st.push(num);
        }
        vector<int> res;
        for(auto it: nums1 ){
            res.push_back(nge[it]);
        }
        return res;
 }
int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    //Output: [-1,3,-1]
    vector<int> ans = nextGreaterElementOptimises(nums1, nums2);
    for(auto it : ans){
        cout <<  it  << endl;
    }
   
    return 0;
}
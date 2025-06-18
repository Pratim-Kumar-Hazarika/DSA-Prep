
#include<iostream>
#include<stack>
using namespace std;

  vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        vector<int> st;
        for(int i = 0 ; i<n ; i++){ //O(N)
            if(arr[i] > 0){
                st.push_back(arr[i]);
            }else{
                while(!st.empty() && st.back() > 0 && st.back() < abs(arr[i])){  //O(N)
                    st.pop_back();
                }
                if(!st.empty() && st.back() == abs(arr[i])){
                    st.pop_back();
                }else if(st.empty()  || st.back() <0){
                    st.push_back(arr[i]);
                }
                
            }
        }
        return st;
        //TC : O(2N)
        //SC : O(N)
    }

int main(){
    vector<int> arr = {5,10,-5};
    //output  [5,10]
    vector<int> ans = asteroidCollision(arr);
    for(int num : ans){
        cout << num << endl;
    }
    return 0;

}

#include<iostream>
#include<stack>
using namespace std;


class SolutionBrute {
public:
    vector<int> findPse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for (int i = 0; i <n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    };
    vector<int> findNse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    };
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return arr[0];
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi, arr[i] * (nse[i] - pse[i] -1));
        }
        return maxi;
    }
    //TC : O(5N)
    //SC : O(2N) + O(2N)
};
int main(){
    cout << "Largest Rectange in Histogram" << endl;
    vector<int> heights = {2,1,5,6,2,3};
    //output : 10
    SolutionBrute s;
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
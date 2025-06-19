
#include<iostream>
#include<stack>
using namespace std;


int histogram(vector<int>&arr){
        int maxArea = 0;
        int n = arr.size();
        stack<int> st;
        for(int i = 0 ; i< n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int element = st.top(); st.pop();
                int nse = i ;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea,arr[element] *(nse-pse-1));
            }
            st.push(i);
        }
           while(!st.empty() ){
                int element = st.top(); st.pop();
                int nse = n ;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea,arr[element] *(nse-pse-1));
            }
        return maxArea;
    };
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> pSum(n, vector<int>(m,0));
        for(int j = 0 ; j < m ; j++){//O(N)
            int sum = 0;
            for(int i = 0 ; i < n ; i++){//O(M)
                sum+= matrix[i][j]-'0';
                if(matrix[i][j] == '0') sum = 0;
                pSum[i][j] = sum;
            }
        }
        for(int i = 0 ; i< n ; i++){//O(N)
            maxArea = max(maxArea,histogram(pSum[i])); //TC:O(2M)
        }
    //TC :O(M x N) + O(N*2M)
    //SC :O(N x M) + O(N)
        return maxArea;
    }
int main(){

     vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    //Output : 6
    int ans = maximalRectangle(matrix);
    cout << ans << endl;
    
    return 0;
}
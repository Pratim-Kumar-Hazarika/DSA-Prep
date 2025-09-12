#include <iostream>
#include <vector>
#include <numeric>  
#include <climits>

using namespace std;

int findMaxElement(vector<vector<int>>& mat,int n , int m , int col){
        int index= -1;
        int maxElement = -1;
        for(int i = 0 ; i< n ; i++){
            if(mat[i][col] >maxElement){
                maxElement = mat[i][col];
                index = i;
            }
        }
        return index;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0 , high = m-1;
        while(low <= high){
            int mid = (low  + high)/2;
            int row = findMaxElement(mat,n,m,mid);
            int left = mid-1 >=0 ? mat[row][mid-1] : -1 ;
            int right = mid+1 <m ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            if(mat[row][mid] < left) high = mid-1;
            else low=mid+1;
        }
        return {-1,-1};
}
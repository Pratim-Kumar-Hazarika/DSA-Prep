#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
private:
    void dfs(int row , int col, int newColor , int iniColor,vector<vector<int>> &ans,
    vector<vector<int>>& image,int delRow[], int delCol[]){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i  = 0 ;i<4 ; i++){
            int nrow = delRow[i] + row;
            int ncol = delCol[i] + col;
            if(nrow>= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
                  dfs(nrow,ncol,newColor,iniColor,ans,image,delRow,delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] ={-1,0,1,0};
        int delCol[] = {0 , 1 ,0, -1};
        dfs(sr,sc,color,iniColor,ans,image,delRow,delCol);

        return ans;
    }
};
int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Result after flood fill:\n";
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
    //TC : N +  N nodes x 4 (4 neighbours) O(N X M)
    //SC : O ( N X M) + O(N X M)
}

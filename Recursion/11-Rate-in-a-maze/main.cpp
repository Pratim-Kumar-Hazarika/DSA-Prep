#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(int i, int j, int di[], int dj[], vector<string> &ans,
               vector<vector<int>> &vis, string move, int n, int m, vector<vector<int>>& maze) {
        
        if (i == n - 1 && j == m - 1) {
            ans.push_back(move);
            return;
        }

        string dir = "DLRU";
       

        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < m &&
                !vis[nexti][nextj] && maze[nexti][nextj] == 1) {
                     vis[i][j] = 1;
                solve(nexti, nextj, di, dj, ans, vis, move + dir[ind], n, m, maze);
                 vis[i][j] = 0; 
            }
        }

    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        int m = maze[0].size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int di[] = {1, 0, 0, -1};  // D, L, R, U
        int dj[] = {0, -1, 1, 0};

        if (maze[0][0] == 1)
            solve(0, 0, di, dj, ans, vis, "", n, m, maze);

        return ans;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {1, 1, 1, 1}
    };

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);

    if (paths.empty()) {
        cout << "No path found" << endl;
    } else {
        cout << "Paths found:" << endl;
        for (string path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}

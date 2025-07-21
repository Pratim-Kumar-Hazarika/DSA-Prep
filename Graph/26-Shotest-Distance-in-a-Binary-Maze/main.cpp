#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {1, 1}, {-1, 0}, {0, -1}, 
            {-1, -1}, {1, -1}, {-1, 1}
        };

        dist[0][0] = 1;
        pq.push(make_pair(1, make_pair(0, 0)));

        while (!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();

            int d = top.first;
            int r = top.second.first;
            int c = top.second.second;

            if (r == n - 1 && c == n - 1) return d;

            for (int i = 0; i < directions.size(); i++) {
                int dr = directions[i].first;
                int dc = directions[i].second;

                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        pq.push(make_pair(d + 1, make_pair(nr, nc)));
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    int result = sol.shortestPathBinaryMatrix(grid);
    cout << "Shortest Path Length: " << result << endl;

    return 0;
}

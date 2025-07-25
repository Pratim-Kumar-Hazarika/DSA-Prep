#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000000;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> dist = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    Solution sol;
    sol.floydWarshall(dist);

    cout << "Shortest distance matrix:\n";
    for (auto row : dist) {
        for (auto val : row) {
            if (val == INF)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}

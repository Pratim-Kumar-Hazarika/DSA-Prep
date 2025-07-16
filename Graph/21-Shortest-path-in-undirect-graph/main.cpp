#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int> dist(V, INT_MAX);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

int main() {

    int V = 9;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
        {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src = 0;
    Solution sol;
    vector<int> result = sol.shortestPath(adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < result.size(); i++) {
        cout << i << ": " << result[i] << endl;
    }

    return 0;
}

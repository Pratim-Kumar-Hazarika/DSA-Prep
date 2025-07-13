#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis)) return true;
            } else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &adj) {
        vector<int> vis(V, 0), pathVis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

int main() {
    // Sample input: 5 vertices, 3 edges
    int V = 5;
    vector<pair<int, int>> edges = {
        {3, 0},
        {4, 2},
        {1, 2}
    };

    vector<vector<int>> adj(V);
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }

    Solution sol;
    cout << (sol.isCyclic(V, adj) ? "true\n" : "false\n");

    return 0;
}

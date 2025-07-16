#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  private:
    void topoSort(int node, vector<int>&vis, stack<int>& st, vector<pair<int, int>> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, vis, st, adj);
            }
        }
        st.push(node);
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(V, 0); 
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, vis, st, adj);
            }
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] != 1e9 && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};


int main() {
    Solution sol;

    int V = 6;
    int E = 7;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2},
        {4, 5, 4}, {2, 3, 6}, {5, 3, 1}
    };

    vector<int> result = sol.shortestPath(V, E, edges);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << result[i] << endl;
    }

    return 0;
}

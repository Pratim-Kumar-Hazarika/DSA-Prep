#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    void dfs(vector<int> &vis, int node, stack<int> &st, vector<vector<int>> &adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(vis, it, st, adj);
            }
        }
        st.push(node);
    }

    void dfs2(vector<int> &vis, int node, vector<vector<int>> &adjT) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs2(vis, it, adjT);
            }
        }
    }

    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(vis, i, st, adj);
            }
        }

        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        fill(vis.begin(), vis.end(), 0);
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs2(vis, node, adjT);
            }
        }

        return scc;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> adj = {
        {2, 3},    // Node 0
        {0},       // Node 1
        {1},       // Node 2
        {},        // Node 3
        {5},       // Node 4
        {4}        // Node 5
    };

    cout << "Number of Strongly Connected Components: " << sol.kosaraju(adj) << endl;
    return 0;
}

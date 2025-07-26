#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class DistJointSet {
    vector<int> rank, parent, size;
public:
    DistJointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                if (node < adjNode) {  // avoid pushing both (u,v) and (v,u)
                    edges.push_back({wt, {node, adjNode}});
                }
            }
        }

        DistJointSet ds(V);
        sort(edges.begin(), edges.end());
        int ans = 0;

        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUParent(u) != ds.findUParent(v)) {
                ans += wt;
                ds.unionBySize(u, v);
            }
        }

        return ans;
    }
};

int main() {
    int V = 5;
    cout << "Print" << endl;
    vector<vector<int>> adj[5];

    vector<tuple<int, int, int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    Solution sol;
    int mstWeight = sol.spanningTree(V, adj);

    cout << "Weight of MST is: " << mstWeight << endl;
    return 0;
}

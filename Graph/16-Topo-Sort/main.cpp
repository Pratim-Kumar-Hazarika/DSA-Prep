#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    void dfs(int start, vector<int>& vis, vector<vector<int>>& edges, stack<int>& st) {
        vis[start] = 1;
        for (auto it : edges[start]) {
            if (!vis[it]) {
                dfs(it, vis, edges, st);
            }
        }
        st.push(start);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, edges, st);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main() {
    int V = 4;  // Number of vertices
    int E = 2;  // Number of edges

    vector<vector<int>> edges(V);

    edges[1].push_back(2);
    edges[1].push_back(0);

    Solution sol;
    vector<int> topo = sol.topoSort(V, edges);


    cout << "Topological Sort: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

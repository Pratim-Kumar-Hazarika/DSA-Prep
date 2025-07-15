#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);

        // Reverse the graph
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        // Nodes with 0 indegree in reversed graph are safe
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

// Sample main function
int main() {
    Solution sol;

    // Sample input: directed graph (adjacency list)
    vector<vector<int>> graph = {
        {1, 2},    // Node 0 -> 1, 2
        {2, 3},    // Node 1 -> 2, 3
        {5},       // Node 2 -> 5
        {0},       // Node 3 -> 0 (cycle)
        {5},       // Node 4 -> 5
        {},        // Node 5 -> terminal node
        {}         // Node 6 -> terminal node
    };

    vector<int> result = sol.eventualSafeNodes(graph);

    // Output safe nodes
    cout << "Safe nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

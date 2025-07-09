#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> ans;
        queue<int> q;
        vector<int> vis(n, 0);
        vis[0] = 1;
        q.push(0);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

int main() {
    int n = 5; 
    vector<vector<int>> adj(n);

    // Example edges (undirected graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    Solution sol;
    vector<int> result = sol.bfs(adj);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
    ///SC : O(n) for visited array and queue
    //TC : O(n) +O(2E)
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 private:
    int timer = 0;
    void dfs(int node , int parent , int tin[], int low[],  vector<int> &vis,
             vector<int> &mark ,vector<int> adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, tin, low, vis, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

 public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> vis(n, 0), mark(n, 0);
        int tin[n], low[n];

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, tin, low, vis, mark, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i]) ans.push_back(i);
        }

        if (ans.empty()) return {-1};
        return ans;
    }
};

int main() {
    int n = 5;
    vector<int> adj[n];

    // Sample edges: [[0,1],[1,2],[2,0],[1,3],[3,4]]
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution sol;
    vector<int> result = sol.articulationPoints(n, adj);

    cout << "Articulation Points: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

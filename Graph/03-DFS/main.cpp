#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    void dfs(int node, vector<int>& ans, vector<int>&vis,vector<vector<int>>& adj){
        vis[node]=1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                  dfs(it,ans,vis,adj);
            }
        }
    };
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<int> vis(n,0);
        dfs(0,ans,vis,adj);
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
    vector<int> result = sol.dfs(adj);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
    ///SC : O(n) for visited array and queue
    //TC : O(n) +O(2E)
}

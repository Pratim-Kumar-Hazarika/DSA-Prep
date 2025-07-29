#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
private:
    int timer = 1;
public:
    void dfs(int node,int parent,int tin[],int low[],vector<int> &vis,vector<int> adj[],vector<vector<int>> &ans){
        vis[node] = 1;
        tin[node]= low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                 dfs(it,node,tin,low,vis,adj,ans);
                 low[node] = min(low[node],low[it]);
                 if(low[it] > tin[node]){
                    ans.push_back({it,node});
                 }
            }else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> ans;
        dfs(0,-1,tin,low,vis,adj,ans);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> result = sol.criticalConnections(n, connections);

    for (auto& conn : result) {
        cout << conn[0] << " - " << conn[1] << endl;
    }
    return 0;
}

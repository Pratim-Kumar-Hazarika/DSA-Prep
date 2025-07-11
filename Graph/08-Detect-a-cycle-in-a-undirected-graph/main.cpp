#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool bfs(int src , vector<int>& vis,vector<vector<int>>& adj){
        vis[src] =1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                     vis[it] = 1;
                    q.push({it,node});
                   
                }
                else if(parent != it){
                    return true;
                }
            }
        }
    //TC : O(N) +O(2E)
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
               if( bfs(i,vis,adj) == true) return true;
            }
        }
        return false;
        
    }
};
class Solution2 {
private:
    bool dfs(int node , int parent , vector<int>&vis,vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode,node,vis,adj)==true)return true;
            }
            else if(adjNode != parent) return true;
        }
        return false;
    };
  public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
               if( dfs(i,-1,vis,adj) == true) return true;
            }
        }
        return false;
        
    }
};
int main() {
    Solution2 sol;

    // Number of vertices
    int V = 3;

    // Adjacency list
    vector<vector<int>> adj(V);

    // Add edges (undirected graph with cycle)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    // Check for cycle
    if (sol.isCycle(V, adj)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle in the graph." << endl;
    }

    return 0;
}

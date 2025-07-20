#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<vector<int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // Remove this line if graph is directed
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, 1e9);
        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (d + edgeWeight < dis[adjNode]) {
                    dis[adjNode] = d + edgeWeight;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        return dis;
    }
};



class SolutionSet {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<vector<int>>> adj(V);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
    vector<int> dis(V, 1e9);
    set<pair<int,int>>st;
        st.insert({0,src});
        dis[src] = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int d = it.first;
            int node = it.second;
            
            st.erase(it);
            
            for(auto &it : adj[node]){
                int adjNode = it[0];
                int adjDis = it[1];
                if(d + adjDis < dis[adjNode]){
                    if(dis[adjNode] != 1e9){
                        st.erase({dis[adjNode],adjNode});
                    }
                    dis[adjNode] = d+adjDis;
                    st.insert({dis[adjNode],adjNode});
                }
            }
            
        }
        return dis;
       
    }
};

int main() {
    int V = 3;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 3},
        {0, 2, 6}
    };
    int src = 2;

    Solution sol;
    vector<int> result = sol.dijkstra(V, edges, src);

    cout << "Shortest distances from node " << src << ": ";
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                if(cost + edW < dist[adjNode]) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int src = 0;
    int dst = 3;
    int k = 1;

    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price from " << src << " to " << dst << " with at most " << k << " stops: " << result << endl;

    return 0;
}

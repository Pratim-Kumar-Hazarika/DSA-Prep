#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return topo.size() == V;
    }
};

int main() {
    Solution sol;

    // Example 1: Can finish all courses
    int V1 = 4;
    vector<vector<int>> prerequisites1 = {
        {1, 0}, {2, 1}, {3, 2}
    };
    cout << "Can finish courses (Example 1)? " << (sol.canFinish(V1, prerequisites1) ? "Yes" : "No") << endl;

    // Example 2: Has cycle, can't finish all courses
    int V2 = 2;
    vector<vector<int>> prerequisites2 = {
        {1, 0}, {0, 1}
    };
    cout << "Can finish courses (Example 2)? " << (sol.canFinish(V2, prerequisites2) ? "Yes" : "No") << endl;

    return 0;
}

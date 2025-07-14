#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class SolutionDFS {
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

class SolutionBFS {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> edges(V);

    edges[5].push_back(2);
    edges[5].push_back(0);
    edges[4].push_back(0);
    edges[4].push_back(1);
    edges[2].push_back(3);
    edges[3].push_back(1);

    SolutionDFS solDFS;
    vector<int> topoDFS = solDFS.topoSort(V, edges);

    cout << "Topological Sort (DFS): ";
    for (int node : topoDFS) {
        cout << node << " ";
    }
    cout << endl;

    SolutionBFS solBFS;
    vector<int> topoBFS = solBFS.topoSort(V, edges);

    cout << "Topological Sort (BFS): ";
    for (int node : topoBFS) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
///Topo Sort Khans Algorithm ( BFS ) 
//Indegree
//push indegree == 0 in queue
////pop from queue and push in ans
//decrease indegree of neighbours
////if indegree of neighbour becomes 0, push it in queue
//Continue until queue is empty
////Time Complexity: O(V + E)
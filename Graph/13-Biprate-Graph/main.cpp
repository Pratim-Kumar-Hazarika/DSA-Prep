#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SolutionBFS {
public:
    bool bfs(int start, vector<int> &color, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(start);
        color[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartiteBFS(vector<vector<int>> &graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (bfs(i, color, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

class SolutionDFS {
public:
    bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph) {
        color[node] = col;

        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (dfs(it, !col, color, graph) == false) return false;
            } else if (color[it] == col) return false;
        }
        return true;
    }

    bool isBipartiteDFS(vector<vector<int>> &graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};

int main() {
    // Example graph: bipartite
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    SolutionBFS solBFS;
    SolutionDFS solDFS;

    cout << "BFS check: ";
    if (solBFS.isBipartiteBFS(graph)) {
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is NOT Bipartite" << endl;
    }

    cout << "DFS check: ";
    if (solDFS.isBipartiteDFS(graph)) {
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is NOT Bipartite" << endl;
    }

    return 0;
}

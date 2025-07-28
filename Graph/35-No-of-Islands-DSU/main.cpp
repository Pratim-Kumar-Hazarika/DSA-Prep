#include <iostream>
#include <vector>
using namespace std;

// DSU (Disjoint Set Union) class
class DistJointSet {
    vector<int> rank, parent, size;
public:
    DistJointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Solution class with numOfIslands
class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DistJointSet ds(n * m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        vector<int> ans;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (auto it : operators) {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int nodeNo = row * m + col;
            for (int i = 0; i < 4; i++) {
                int adjr = row + delRow[i];
                int adjc = col + delCol[i];
                if (adjr >= 0 && adjc >= 0 && adjr < n && adjc < m) {
                    if (vis[adjr][adjc] == 1) {
                        int adjNode = adjr * m + adjc;
                        if (ds.findUParent(nodeNo) != ds.findUParent(adjNode)) {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

// Main function to test
int main() {
    Solution sol;
    int n = 4, m = 5;

    vector<vector<int>> operators = {
        {1, 1},
        {0, 1},
        {3, 3},
        {3, 4}
    };

    vector<int> result = sol.numOfIslands(n, m, operators);

    cout << "Number of islands after each operation:" << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

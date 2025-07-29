#include <iostream>
#include <vector>
#include <set>
using namespace std;

class DistJointSet {
public:
    vector<int>  parent, size;
    DistJointSet(int n) {
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

class Solution {
public:
    bool isValid(int nrow , int ncol , int n){
        return nrow >= 0 && ncol >= 0 && nrow < n && ncol < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DistJointSet ds(n * n);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Union connected 1s
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                for (int i = 0; i < 4; i++) {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int node = row * n + col;
                        int adjNode = nrow * n + ncol;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        // Step 2: Try converting 0 to 1
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                set<int> components;
                for (int i = 0; i < 4; i++) {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        components.insert(ds.findUParent(nrow * n + ncol));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        // Step 3: If all are 1s
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUParent(cellNo)]);
        }

        return mx;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}
    };

    Solution sol;
    int result = sol.largestIsland(grid);
    cout << "Largest possible island size: " << result << endl;

    return 0;
}

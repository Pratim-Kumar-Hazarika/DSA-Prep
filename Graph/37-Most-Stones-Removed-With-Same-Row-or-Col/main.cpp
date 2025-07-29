#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DistJointSet {
public:
    vector<int> parent, size;
    DistJointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
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
    int removeStones(vector<vector<int>>& stones) {
        DistJointSet ds(20001);  // Enough to separate row and col
        unordered_map<int, int> stoneNodes;

        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + 10001;  // prevent overlap with row
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUParent(it.first) == it.first) {
                cnt++;
            }
        }

        return stones.size() - cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> stones = {{3,2}, {3,1}, {4,4}, {1,1}, {0,2}, {4,0}};
    int result = sol.removeStones(stones);
    cout << "Maximum number of stones that can be removed: " << result << endl;
    return 0;
}

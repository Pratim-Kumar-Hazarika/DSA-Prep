#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;

        queue<pair<int, int>> q;
        vector<int> dist(100000, 1e9);
        q.push({start, 0});
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr) {
                int num = (it * node) % 100000;
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    if (num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    // Example input:
    vector<int> arr = {9, 12, 18, 19};
    int start = 5;
    int end = 5;

    int result = sol.minimumMultiplications(arr, start, end);
    cout << "Minimum multiplications to reach from " << start << " to " << end << ": " << result << endl;

    return 0;
}

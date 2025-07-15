#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> topoSort(vector<vector<int>> &adj, vector<bool>& present) {
        int V = adj.size();
        vector<int> indegree(V, 0);
        vector<int> topo;
        queue<int> q;

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) count++;
        }
        if (topo.size() != count) return {};

        return topo;
    }

public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<bool> present(26, false);
        
        for (string& word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        int N = words.size();
        for (int i = 0; i < N - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            if (s1.size() > s2.size() && s1.substr(0, len) == s2) {
                return "";
            }

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(adj, present);
        if (topo.empty()) return "";

        string ans = "";
        for (int i : topo) {
            if (present[i]) {
                ans += (char)(i + 'a');
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"baa", "abcd", "abca", "cab", "cad"};
    string result1 = sol.findOrder(words1);
    cout << "Alien Order (Test 1): " << result1 << endl;

    vector<string> words2 = {"caa", "aaa", "aab"};
    string result2 = sol.findOrder(words2);
    cout << "Alien Order (Test 2): " << result2 << endl;

    vector<string> words3 = {"ab", "cd", "ef", "ad"};
    string result3 = sol.findOrder(words3);
    cout << "Alien Order (Test 3): " << result3 << endl;

    return 0;
}

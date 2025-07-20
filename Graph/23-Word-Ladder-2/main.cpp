#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        vector<vector<string>> ans;
        usedOnLevel.push_back(beginWord);
        int level = 0;

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();

            // erase all words that have been used in the previous level
            if (vec.size() > level) {
                level++;
                for (auto& it : usedOnLevel) {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();
            if (word == endWord) {
                if (ans.empty()) {
                    ans.push_back(vec);
                } else if (ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word) > 0) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);

    cout << "All shortest transformation sequences:\n";
    for (auto& path : result) {
        for (auto& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

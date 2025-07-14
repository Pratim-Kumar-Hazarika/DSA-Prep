#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int node ,vector<int>& vis,vector<int>& pathVis,vector<int> &checkVis,vector<vector<int>>& graph){
        vis[node]= 1;
        pathVis[node]=1;
        checkVis[node]=0;
        for(auto it : graph[node]){
            if(!vis[it]){
                if( dfs(it,vis,pathVis,checkVis,graph)==true){
                    checkVis[node]=0;
                    return true;
                }
            }else if(pathVis[it]){
                checkVis[node]=0;
                    return true;
            }
        }

        checkVis[node]=1;
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> checkVis(V,0);
        vector<int> ans;
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,checkVis,graph);
            }
        }
        for(int i = 0 ; i < V ; i++){
            if(checkVis[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
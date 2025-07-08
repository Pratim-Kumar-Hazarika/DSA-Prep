#include<iostream>

using namespace std;

int main(){

    ///Adjacency List
    int n, m;
    cin >> n >> m;
    int adj[n+1][m+1];
    //SC : n^2 lot of places will be unused
    for(int i = 0 ;i < m ; i++){
        int u ,v;
        cin >> u >> v;
        adj[u][v] = 1 ;
        adj[v][u] = 1;
    }

    vector<int>adj1[n+1];
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    //Space : O(2E) every edge has 2 nodes undirected graph


    //Space : O(E) directed graph
    vector<int>adj2[n+1];
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj2[u].push_back(v);
        // adj1[v].push_back(u);
    }
    
    //Weighted Graph
      vector<pair<int,int>> adj3[n+1];
    for(int i = 0 ; i < m ; i++){
        int u , v, wt;
        cin >> u >> v >> wt;
        adj3[u].push_back({v, wt}); // directed
        // If undirected, also add:
        // adj2[v].push_back({u, wt});
    }
    return 0;
}
//Note : We will use visited array in Graphs
//We run a loop if a node is not visited we called a traversal algorithm
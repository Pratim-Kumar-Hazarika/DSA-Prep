#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  

using namespace std;

class DistJointSet{
    vector<int> rank,parent,size;
 public:

    DistJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i = 0 ; i< n ; i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_v = findUParent(v);
        int ulp_u = findUParent(u);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
              parent[ulp_v] = ulp_u;
              rank[ulp_u]++;
        }
    }

     void unionBySize(int u , int v){
        int ulp_v = findUParent(v);
        int ulp_u = findUParent(u);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};


int main(){
    cout << "Disjoint set" << endl;
    DistJointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same\n";
    }else cout << "Not same\n";

    ds.unionBySize(3,7);

       if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same\n";
    }else cout << "Not same\n";

}
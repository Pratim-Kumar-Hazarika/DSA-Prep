#include <iostream>
#include <vector>
 using namespace std;

 void printf(int ind , vector<int>&ds , int arr[], int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " "; 
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    printf(ind+1,ds,arr,n);
    ds.pop_back();
    printf(ind+1,ds,arr,n);
 }
 int main(){
     vector<int> ds;
     int arr[] ={3,1,2};
     int n = 3;
    printf(0,ds,arr,n);
 }

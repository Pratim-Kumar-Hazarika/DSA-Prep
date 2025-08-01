#include <iostream>
#include <vector>
 using namespace std;

 void printf(int ind , vector<int>&ds , int arr[], int n,int s , int curSum){
    if(ind == n){
       if( curSum == s){
           for(auto it : ds){
               cout << it << " ";
           }
       }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    curSum+= arr[ind];
    printf(ind+1,ds,arr,n,s,curSum);
    ds.pop_back();
    curSum-= arr[ind];
    printf(ind+1,ds,arr,n,s,curSum);
 }
 int main(){
     vector<int> ds;
     int arr[] ={1,2,1};
     int sum = 2;
     int n = 3;
    printf(0,ds,arr,n,sum,0);
 }

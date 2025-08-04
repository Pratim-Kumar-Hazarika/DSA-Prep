#include <iostream>
#include <vector>
 using namespace std;

//Print all subsequences of an array whose sum is equal to a given value 's'
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
 //Just print one subsequence of an array whose sum is equal to a given value 's'
  bool printf1(int ind , vector<int>&ds , int arr[], int n,int s , int curSum){
    if(ind == n){
       if( curSum == s){
           for(auto it : ds){
               cout << it << " ";
           }
           return true;
       }
        // cout << endl;
        return false;
    }
    ds.push_back(arr[ind]);
    curSum+= arr[ind];
    if(printf1(ind+1,ds,arr,n,s,curSum) == true) return true;
    ds.pop_back();
    curSum-= arr[ind];
 if(printf1(ind+1,ds,arr,n,s,curSum) == true) return true;
 return false;
 }
 

 ///count subsequences of an array whose sum is equal to a given value 's'
 int returnCountOfSubsequence(int ind , int arr[], int n,int s , int curSum){
    if(curSum > s) return 0; // If current sum exceeds 's', no need to proceed further
    if(ind == n){
       if( curSum == s){
         
           return 1;
       }
        // cout << endl;
        return 0;
    }
    curSum+= arr[ind];
    int lh = returnCountOfSubsequence(ind+1,arr,n,s,curSum) ;
    curSum-= arr[ind];
  int rh = returnCountOfSubsequence(ind+1,arr,n,s,curSum) ;
 return lh+rh;
 }

 int main(){
     vector<int> ds;
     int arr[] ={1,2,1};
     int sum = 2;
     int n = 3;
    printf(0,ds,arr,n,sum,0);
    printf1(0,ds,arr,n,sum,0);
      cout << returnCountOfSubsequence(0,arr,n,sum,0);
 }

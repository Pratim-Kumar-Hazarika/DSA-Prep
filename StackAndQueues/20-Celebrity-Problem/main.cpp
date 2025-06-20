#include<iostream>
#include<stack>
using namespace std;


int celebrity(vector<vector<int> >& mat) {
        int n = mat[0].size();
        vector<int> knowMe(n,0);
        vector<int> iKnow(n,0);
        
        for(int i = 0 ; i < n ; i++){ //O (N) X O(M)
            for(int j = 0 ; j< n ; j ++){
                if( i != j && mat[i][j] == 1){
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }
        for(int i = 0 ; i< n ; i++){ //O(N)
            if(knowMe[i] == n-1 && iKnow[i] == 0){
                return i;
            }
        }
        return -1;
        //TC : O(N * N ) + O(N)
        //SC : O(2N)
    }
int main(){
     vector<vector<int>> mat = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };

    int result = celebrity(mat);
    cout << "Celebrity Index: " << result << endl; 
    return 0;
    return 0;
}
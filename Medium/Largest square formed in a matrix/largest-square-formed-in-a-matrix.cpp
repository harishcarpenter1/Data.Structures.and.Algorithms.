//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>>&mat, int i, int j, int n, int m, int &maxi, 
    vector<vector<int>>&dp){
        if(i ==n || j == m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solve(mat, i, j+1, n, m, maxi, dp);
        int bottom = solve(mat, i+1, j, n, m, maxi, dp);
        int dig = solve(mat, i+1, j+1, n, m, maxi, dp);
        if(mat[i][j]==1){
            int ans = 1 + min({right, bottom, dig});
            maxi = max(maxi, ans);
            return dp[i][j]=ans;
        }else{
            return dp[i][j]=0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        solve(mat, 0, 0, n, m, maxi, dp);
        return maxi;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
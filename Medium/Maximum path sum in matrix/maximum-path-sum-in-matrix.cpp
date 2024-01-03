//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// class Solution{
// public:
//     int solve(vector<vector<int>> m, int n, int i, int j,
//     vector<vector<int>>&dp){
//         if(i==n-1 && j<n) return m[n-1][j];
//         if(i>n or j>=n or j<0) return -1e9;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int a = m[i][j]+solve(m,n,i+1,j,dp);
//         int b = m[i][j]+solve(m,n,i+1,j-1,dp);
//         int c = m[i][j]+solve(m,n,i+1,j+1,dp);
//         return dp[i][j]=max({a,b,c});
//     }
//     int maximumPath(int n, vector<vector<int>> m)
//     {
//         int ans = 0;
//         vector<vector<int>>dp(n, vector<int>(n, -1));
//         for(int i = 0; i<n; i++){
//             ans=max(ans, solve(m,n,0,i,dp));
//         }
//         return ans;
//     }
// };

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> m)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the dp array with the last row of the matrix
        for (int i = 0; i < n; i++) {
            dp[n-1][i] = m[n-1][i];
        }

        // Bottom-up calculation
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int a = (j > 0) ? dp[i+1][j-1] : 0;
                int b = dp[i+1][j];
                int c = (j < n-1) ? dp[i+1][j+1] : 0;

                dp[i][j] = m[i][j] + max({a, b, c});
            }
        }

        // Find the maximum value in the first row
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[0][i]);
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
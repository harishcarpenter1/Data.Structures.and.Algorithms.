//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     vector<vector<int>>mat(n, vector<int>(n, 1e9));
                     for(auto it:edges){
                         int u = it[0];
                         int v = it[1];
                         int wt = it[2];
                         
                         mat[u][v] = wt;
                         mat[v][u] = wt;
                     }
                     
                     for(int i = 0; i<n; i++) mat[i][i] = 0;
                     
                     int cntCities = n;
                     int city = -1;
                     
                     for(int k = 0; k<n; k++){
                         for(int i = 0; i<n; i++){
                             for(int j = 0; j<n; j++){
                                 if(mat[i][k] != 1e9 && mat[k][j] != 1e9){
                                     mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                                 }
                             }
                         }
                     }
                     
                     
                     for(int i = 0; i<n; i++){
                         int cnt = 0;
                         for(int j = 0; j<n; j++){
                             if(mat[i][j] <= distanceThreshold) cnt++;
                         }
                         
                         if(cnt < cntCities){
                             cntCities = cnt;
                             city = i;
                         }
                         else if(cnt == cntCities){
                             city = i;
                         }
                     }
                     
                     
                     return city;
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
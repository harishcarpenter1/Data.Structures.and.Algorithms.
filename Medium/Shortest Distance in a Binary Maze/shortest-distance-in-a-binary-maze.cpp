//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> desti) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        
        priority_queue<pair<int,pair<int,int> >,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> >pq;
        
        pq.push({0, {source.first, source.second} });
        
        vector<int>dr = {-1, 0, 1, 0};
        vector<int>dc = {0, 1, 0, -1};
        
        while(!pq.empty()){
            auto it = pq.top();
            int i = it.second.first;
            int j = it.second.second;
            int d = it.first;
            
            pq.pop();
            
            for(int k = 0; k<4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && 
                grid[nr][nc] == 1 && d + 1 < dist[nr][nc]){
                    dist[nr][nc] = d + 1;
                    pq.push({dist[nr][nc], {nr,nc} });
                }
            }
        }
        
        if(dist[desti.first][desti.second] == 1e9) return -1;
        return dist[desti.first][desti.second];
        
     }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
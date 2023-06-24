//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis = grid;
        queue<pair<pair<int,int>, int>>q;
        
        int cntf = 0;
        
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) cntf++;
            }
        }
        
        vector<int>dr = {-1, 0, 1, 0};
        vector<int>dc = {0, 1, 0, -1};
        
        int tm = 0, cnt = 0;
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            
            q.pop();
            tm = max(tm, time);
            
            for(int k = 0; k<4; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m 
                && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                    vis[nr][nc] = 2;
                    cnt++;
                    q.push({{nr,nc},time+1});
                }
            }
            
        }
        
        if(cntf == cnt) return tm;
        else return -1;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
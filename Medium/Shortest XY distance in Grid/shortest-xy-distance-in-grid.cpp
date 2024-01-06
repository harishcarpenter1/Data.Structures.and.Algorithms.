//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) 
    {
       vector<vector<bool>> vis(n,vector<bool>(m,false));
       queue<pair<int,pair<int,int>>> q;
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]=='X')
               {
                   vis[i][j]=true;
                   q.push({0,{i,j}});
               }
               
           }
       }
       
       int delr[]={-1,1,0,0};
       int delc[]={0,0,-1,1};
       
       while(!q.empty())
       {
           int d=q.front().first;
           int x=q.front().second.first;
           int y=q.front().second.second;
           q.pop();
           
           if(grid[x][y]=='Y')
           {
               return d;
           }
           
           for(int k=0;k<4;k++)
           {
            int newr=x+delr[k];
            int newc=y+delc[k];
            
            if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==false)
            {
                q.push({d+1,{newr,newc}});
                vis[newr][newc]=true;
            }
           }
       }
       return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
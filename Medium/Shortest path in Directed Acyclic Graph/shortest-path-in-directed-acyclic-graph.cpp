//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private:
  void dfs(vector<vector<pair<int,int>>>&dg, vector<int>&vis, stack<int>&st, 
  int node){
      vis[node] = 1;
      for(auto it:dg[node]){
          if(!vis[it.first]){
              dfs(dg,vis,st,it.first);
          }
      }
      st.push(node);
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& ed){
         
        vector<vector<pair<int,int>>>dg(N);
        for(auto it : ed){
            dg[it[0]].push_back({it[1],it[2]});
        }
        
        int src = 0;
        stack<int>st;
        vector<int>dist(N, 1e9);
        vector<int>vis(N,0);
        
        dist[src] = 0;
        
        for(int i = 0; i<N; i++){
            if(!vis[i]){
                dfs(dg, vis, st, i);
            }
        }
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
             for(auto ad : dg[node]){
                 if(dist[node]+ad.second < dist[ad.first]){
                     dist[ad.first] = dist[node]+ad.second;
                 }
             }
        }
        
        
        for(int i = 0; i<N; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
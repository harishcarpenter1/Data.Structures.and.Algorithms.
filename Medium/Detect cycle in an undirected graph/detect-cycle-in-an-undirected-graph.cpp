//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool bfs(vector<int>adj[], vector<int>&vis, int i){
        queue<pair<int,int>>q;
        vis[i] = 1;
        q.push({i,-1});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto nb : adj[node]){
                if(vis[nb] == 0){
                    q.push({nb,node});
                    vis[nb] = 1;
                }
                else if(vis[nb] && parent != nb) return  true;
            
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
       vector<int>vis(v,0);
       for(int i = 0; i<v; i++){
           if(!vis[i]){
               if(bfs(adj,vis, i)){
                   return true;
               }
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    int timer = 1;
    void dfs(vector<int>adj[], vector<int>&vis, vector<int>&markAP, vector<int>&low, 
   vector<int>&stp, int node, int parent){
        vis[node] = 1;
        low[node] = timer;
        stp[node] = timer;
        timer++;
        int childcnt = 0;
        for(auto adjNode:adj[node]){
            // If the adjasecnt not visited
            if(adjNode == parent) continue;
            if(vis[adjNode] == 0){
                dfs(adj, vis, markAP, low, stp, adjNode, node);
                low[node] = min(low[node], low[adjNode]);
                //  Checking for AP
                if(low[adjNode] >= stp[node] && parent != -1){
                    markAP[node] = 1;
                }
                childcnt++;
            }
            else{
                low[node] = min(low[node], stp[adjNode]);
            }
           
        }
        if(parent == -1 && childcnt > 1){
             markAP[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
      
        vector<int>vis(n,0);
        vector<int>low(n);
        vector<int>stp(n);
        vector<int> markAP(n,0);
        vector<int>ans;
        
        // Checking for ever components
        for(int i  = 0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, markAP, low, stp, i, -1);
            }
        }
        
        // Marked AP
        for(int i = 0; i<n; i++){
            if(markAP[i]){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
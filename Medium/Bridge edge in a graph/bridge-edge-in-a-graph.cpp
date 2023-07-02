//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    int timer=1;
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        int ans=0;
        dfs(c, -1, adj, vis, tin, low, ans, c, d);
        return ans;
    }
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, int tin[], int low[], int& ans, int c, int d){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it, node, adj, vis, tin, low, ans, c, d);
                low[node]=min(low[it], low[node]);
                if(tin[node]<low[it] && it==d && node==c)
                {
                    ans=1;
                }
            }
            else{
                low[node]=min(low[node], low[it]);
            }
        }
    } 
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends
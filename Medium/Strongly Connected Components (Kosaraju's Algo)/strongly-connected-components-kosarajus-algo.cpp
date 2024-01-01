//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(vector<vector<int>>& adj, vector<int>&vis, int node, stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it,st);
            }
        }
        st.push(node);
    }
    
    void dfs3(vector<vector<int>>&adjT, int node, vector<int>&vis){
        vis[node]=1;
        for(auto it:adjT[node]){
            if(!vis[it]){
                dfs3(adjT, it, vis);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        vector<int>vis(n,0);
        stack<int>st;
        
        // step 1 : Get the node according to their fininsh time 
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i, st);
            }
        }
        
        // step 2 reverse the graph edges 
        vector<vector<int>>adjT(n);

        for(int i = 0; i<n; i++){
            vis[i]=0;
            // edge from i to it 
            // reverse edge will be it to i
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        // step 3 find the scc using dfs
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(adjT, node, vis);
            }
        }
        
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
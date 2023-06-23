//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs1(vector<vector<int>>&adj, vector<int>&vis, stack<int>&st, int node){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs1(adj, vis, st, it);
            }
        }
        st.push(node);
    }
    void dfs3(vector<vector<int>>&adj, vector<int>&vis, int node){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs3(adj, vis, it);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //  step 1. sort the edges based on finish time
        stack<int>st;
        vector<int>vis(V, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs1(adj, vis, st, i);
            }
        }
        
        // step 2. Reverse the edges
        vector<vector<int>>revG(V);
        for(int i = 0; i<V; i++){
            // Marking all nodes unvisited
            vis[i] = 0;
            for(auto it:adj[i]){
                // edge from i - > it
                // reverseedge it - > i
                revG[it].push_back(i);
            }
        }
        
        // 3. Apply DFS again to find SCCs
        int cntSCC = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
           
            if(!vis[node]){
                cntSCC++;
                dfs3(revG, vis, node);
            }
            
        }
        return cntSCC;
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
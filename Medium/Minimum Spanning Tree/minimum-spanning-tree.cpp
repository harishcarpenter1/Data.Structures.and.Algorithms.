//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint{
    private:
    vector<int>rank,parent,size;
    public:
    Disjoint(int n){
        rank.resize(n+1, 0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUltParent(int node){
        if(node == parent[node]) return node;
        // Path Compression
        return parent[node] = findUltParent(parent[node]);
    }
    void UnionByRank(int u, int v){
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        
        // if(ult_u == ult_v){
        //     continue;
        // }
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }else if(rank[ult_v] < ult_u){
            parent[ult_v] = ult_u;
        }
        else{
             parent[ult_v] = ult_u;
             rank[ult_u]++;
        }
    }
    void UnionBySize(int u, int v){
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        
        // if(ult_u == ult_v){
        //     continue;
        // }
        if(size[ult_u] > size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else{
             parent[ult_u] = ult_v;
             size[ult_v] += size[ult_u];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>>g;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                g.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(g.begin(),g.end());
        Disjoint ds(V);
        int sum = 0;
        
        for(auto it : g){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUltParent(u) != ds.findUltParent(v)){
                sum+=wt;
                ds.UnionByRank(u,v);
            }
        }
        return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
  private:
    int t = 0;
    void dfs(vector<int>adj[], vector<int>&vis, int node, 
    int parent, vector<int>&mark, int low[], int tin[]){
        vis[node]=1;
        low[node]=tin[node]=t;
        t++;
        int child = 0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(adj,vis,it,node,mark,low,tin);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int>vis(n,0), mark(n,0);
        vector<int>ans;
        int low[n], tin[n];
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(adj,vis,i,-1,mark,low,tin);
            }
        }
        for(int i = 0; i<n; i++) if(mark[i]==1) ans.push_back(i);
        if(ans.size()==0) return {-1};
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
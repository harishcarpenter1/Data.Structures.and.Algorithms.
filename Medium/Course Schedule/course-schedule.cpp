//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, 
    stack<int>& st, int node, vector<int>&pathvis) {
        visited[node] = 1;  
        pathvis[node] = 1;
        
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                if(dfs(adj, visited, st, neighbor, pathvis)) return true;
            }
            else if(pathvis[neighbor]){
                return true;
            }
        }
        
        st.push(node);
        pathvis[node] = 0;
        return false;
    }
    
public:
    vector<int> findOrder(int n, int m, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> order;
        stack<int> st;
        vector<int> visited(n, 0);  
        vector<int> pathvis(n, 0);  
        
        for (auto it : p) {
            adj[it[1]].push_back(it[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if(dfs(adj, visited, st, i, pathvis)){
                    return {};
                }
            }
        }
        
        while (!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        
        return order; 
    }
};



//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
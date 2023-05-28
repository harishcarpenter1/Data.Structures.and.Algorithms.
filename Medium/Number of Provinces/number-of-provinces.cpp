//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfs(vector<int> adjL[], int vis[], int i){
        vis[i] = 1;
        for(auto nb : adjL[i]){
            if(!vis[nb]){
                dfs(adjL,vis,nb);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int v) {
        vector<int>adL[v];
        int vis[v] = {0};
        
        // created a adj list
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(adj[i][j] == 1 && i!=j){
                    adL[i].push_back(j);
                    adL[j].push_back(i);
                }
            }
        }
        // answer variable
        int cnt = 0;
        
        // traversing all unvisited nodes
        for(int i = 0; i<v; i++){
            if(!vis[i]){
                cnt++;
                dfs(adL,vis,i);
            }
        }
        
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
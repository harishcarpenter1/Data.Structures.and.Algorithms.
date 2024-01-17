//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void genperm(vector<int> &arr ,int n, int i, vector<int>&vis, set<vector<int>>&st,
    vector<int>&ds){
        if(ds.size()==n){
            st.insert(ds);
            return;
        }
        for(int i = 0; i<n; i++){
            if(vis[i]==0){
                ds.push_back(arr[i]);
                vis[i]=1;
                genperm(arr,n,i+1,vis,st,ds);
                ds.pop_back();
                vis[i]=0;
            }
        }
        return;
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>>st;
        vector<int>ds, vis(n,0);
        vector<vector<int>>ans;
        genperm(arr,n,0,vis,st,ds);
        for(auto it:st){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
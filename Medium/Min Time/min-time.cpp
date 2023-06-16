//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long 
class Solution {
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        
        // Finding all the left extremes and right extremes of the type i into vector
        map<ll, vector<ll>> mp;
        for(int i = 0; i < n; i++)
        {
            ll type = types[i];
            ll x_pos = locations[i];
            
            if(mp.find(type) == mp.end())
            {
                mp[type] = {x_pos, x_pos};
            }
            else
            {
                mp[type][0] = min(mp[type][0] , x_pos);
                mp[type][1] = max(mp[type][1] , x_pos);
            }
        }
        
        vector<vector<ll>> v;
        // start with 0,0
        v.push_back({0,0});
        
        // Pushing all the left extremes and right extremes of the type i into vector
        for(auto x : mp)
        {
            v.push_back(x.second);
        }
        
        // end with 0,0
        v.push_back({0,0});
        
        // Now total 4 possible routes are possible
        vector<vector<ll>> dp(v.size(), vector<ll>(2, 0));
        for(int i = 1; i < v.size(); i++)
        {
           
            ll r1212 = dp[i - 1][0] + abs(v[i - 1][1] - v[i][0]) + abs(v[i][0] - v[i][1]);
            
            
            ll r2112 = dp[i - 1][1] + abs(v[i - 1][0] - v[i][0]) + abs(v[i][1] - v[i][0]);
            dp[i][0] = min(r1212,r2112);
            
            
            ll r1221 = dp[i - 1][0] + abs(v[i][1] - v[i - 1][1]) + abs(v[i][0] - v[i][1]);
            
            ll r2121 = dp[i - 1][1] + abs(v[i - 1][0] - v[i][1]) + abs(v[i][0] - v[i][1]);
            dp[i][1] = min(r1221,r2121);
        }
        
        
        return dp[v.size()-1][1];
    }
 
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
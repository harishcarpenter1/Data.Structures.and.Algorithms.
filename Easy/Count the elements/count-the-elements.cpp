//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
       vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        vector<int> res;
        // unordered_map<int,int>mp;
        for(int i=0;i<query.size();i++){
            query[i] = a[query[i]];
        }
        int maxi = INT_MIN;
        for(auto x:a){
            // mp[x] = 1;
            maxi = max(x, maxi);
        }
        for(auto x:b){
            // mp[x] += 1;
            maxi = max(x, maxi);
        }
        int mp[maxi+1]={0};
        for(auto x:b){
            mp[x] += 1;
            // maxi = max(x, maxi);
        }
        for(int i=1;i<=maxi;i++){
            mp[i] = mp[i] + mp[i-1];
            // cout<<mp[i]<<" ";
        }
        for(auto q:query){
            res.push_back(mp[q]);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
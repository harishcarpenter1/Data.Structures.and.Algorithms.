//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
        int mod = 1e9+7;
        ll c0 = 1,c1 = 1;
        while (--n){
            ll t0 = (c0+c1)%mod,t1 = c0;
            c0 = t0,c1 = t1;
        }
        return (c0+c1)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
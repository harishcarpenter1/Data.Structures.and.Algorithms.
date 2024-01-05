//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
	public:
	int TotalWays(int n)
	{
	    long mod = 1e9+7;
	    long ans, a = 1, b = 1, c = 0;
	    for(int i = 0; i<n; i++){
	        c = (a%mod + b%mod)%mod;
	        a  = b%mod;
	        b  = c%mod;
	    }
	    ans = (int)((c*c)%mod);
	    return ans;
	}
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
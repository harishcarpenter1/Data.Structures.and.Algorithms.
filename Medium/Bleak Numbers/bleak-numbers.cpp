//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int is_bleak(int n)
    {
        for(int i=30,j = n;i>0 && j>0;i--,j--)
            if(j + __builtin_popcount(j) == n) return 0;
        return 1;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends
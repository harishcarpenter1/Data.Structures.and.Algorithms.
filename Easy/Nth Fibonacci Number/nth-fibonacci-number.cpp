//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod = 1e9 + 7;
    int nthFibonacci(int n){
        // code here
        if(n == 1)
            return 0;
        else if(n == 2)
            return 1;
        else
        {
            int c = 2;
            int prev = 0;
            int next = 1;
            while(c <= n)
            {
                int curr = ((prev%mod) + (next%mod))%mod;
                prev = next%mod;
                next = curr%mod;
                c++;
            }
            return next;
        }
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
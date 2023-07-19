//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(string s1, string s2) {
    
        int n=s1.size();
        int m=s2.size();
    
        vector<int> prev(m+1,0), cur(m+1,0);
        
        // Base Case is covered as we have initialized the prev and cur to 0.
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    cur[ind2] = 1 + prev[ind2-1];
                else
                    cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
            }
            prev= cur;
        }
        
        return prev[m];
    }
    int longestPalinSubseq(string A) {
       string B = "";
       for(int i = A.size()-1; i>=0; i--) B+=A[i]; 
       return lcs(A,B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
// #define ll long long
// #define ll long long
// #define ll long long
class Solution{
public:
int mod =1e9+7 ;
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<long long> ans; 
        if(n==1)return {1} ;
        if(n==2)return {1,1} ;
         ans = {1,1} ;
        int x= 3; 
        while((x++)<=n)
       {
           vector<long long > a ;
           a.push_back(1); 
           for(int i=0 ; i<ans.size()-1; i++ )
        {
        a.push_back((ans[i]+ans[i+1])%mod) ;
        }
           a.push_back(1) ;
           ans= a; 
       }
       return ans; 
    }
};






//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
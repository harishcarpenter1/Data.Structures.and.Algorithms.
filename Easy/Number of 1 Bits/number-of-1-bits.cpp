//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     
string binary(int n)
  {
     string ans="";
     while(n>0)
     {
         ans+=to_string(n%2);
         n=n/2;
     }
     //reverse(ans.begin(),ans.end());
     return ans;
  }
    int setBits(int N) {
       string k=binary(N);
       int count=0;
       for(int i=0;i<k.size();i++)
       {
           if(k[i]=='1')
           count++;
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends
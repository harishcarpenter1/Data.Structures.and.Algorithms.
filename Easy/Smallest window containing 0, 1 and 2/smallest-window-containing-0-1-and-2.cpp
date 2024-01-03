//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        int x = 0, y = 0, z = 0;
        while(j<n){
            if(s[j]=='0') x++;
            else if(s[j]=='1') y++;
            else z++;
            while(x>0&&y>0&&z>0){
                ans=min(ans,j-i+1);
                if(s[i]=='0') x--;
                else if(s[i]=='1') y--;
                else z--;
                i++;
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        
        for(int i = 0; i<r ;i++)
        {
            string prev = "";
            for(int j = 0; j<n/2 +1; j++)
            {
                if(s[j] == '1')
                {
                    prev += "10";
                }
                else prev += "01";
            }
            s = prev;
        }
        
        return s[n];
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
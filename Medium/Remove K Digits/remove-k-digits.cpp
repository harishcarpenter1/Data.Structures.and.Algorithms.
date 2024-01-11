//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        stack<char>st;
        int n = S.size();
        if(k==n) return "0";
        for(int i = 0; i<n; i++){
            while(!st.empty() && k>0 && st.top()>S[i]){
                st.pop();
                k--;
            }
            st.push(S[i]);
        }
        if(st.empty()) return "0";
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(i<n && ans[i]=='0') i++;
        if(i==ans.size() || ans.size()==0) return "0";
        return ans.substr(i);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
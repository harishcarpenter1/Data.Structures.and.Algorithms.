//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long solve(string s, int n, int k){
        vector<int>mp(26,0);
        long long i = 0, j = 0, cnt = 0, dist = 0;
        while(i < n){
            if(mp[s[i]-'a'] == 0) dist++;
            mp[s[i]-'a']++;
            while(dist > k){
                mp[s[j]-'a']--;
                if(mp[s[j]-'a'] == 0) dist--;
                j++;
            }
            cnt+=i-j+1;
            i++;
        }
        return cnt;
    }
    long long int substrCount (string s, int k) {
    	int n = s.size();
    	return solve(s,n,k)-solve(s,n,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
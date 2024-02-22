//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

// Memoization
int mod=1e9+7;
class Solution
{
    public:
    int help(string& s,string& t,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(j>=t.length())
        return 1;
        
        if(i>=s.length())
        return 0;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //and small calculation
        int b=0;
        int a=help(s,t,i+1,j,memo);
        if(s[i]==t[j])
        b=help(s,t,i+1,j+1,memo);
        
        return memo[i][j]=(a+b)%mod;
    }
    int subsequenceCount(string s, string t)
    {
        vector<vector<int>> memo(s.length(),vector<int>(t.length(),-1));
       return help(s,t,0,0,memo);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends
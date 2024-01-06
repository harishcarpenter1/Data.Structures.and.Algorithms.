//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{   
public:
    long long solve(int x,int y,string str){
        int n = str.size();
        int cnt1 = 0, cnt2 = 0;
        string s1="pr"; string s2="rp";
        if(x<y){
            swap(s1,s2);
            swap(x,y);
        }
        long long ans = 0;
        stack<char>st;
        for(int i = n-1; i>=0; i--){
            if(!st.empty() && st.top()==s1[1] && str[i]==s1[0]){
                ans+=x;
                st.pop();
            }else{
                st.push(str[i]);
            }
        }
        string rem = "";
        while(!st.empty()){
            rem=st.top()+rem;
            st.pop();
        }
        
        str = rem;
        n = rem.size();
        
        for(int i = n-1; i>=0; i--){
            if(!st.empty() && st.top()==s1[1] && str[i]==s1[0]){
                ans+=y;
                st.pop();
            }else{
                st.push(str[i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
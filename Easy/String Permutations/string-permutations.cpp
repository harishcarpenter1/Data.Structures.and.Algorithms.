//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    int factor(int x){
       if(x==1){
           return 1;
       }
       return x*factor(x-1);
   }
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string>v;
        sort(s.begin(),s.end());
        int x=s.size();
        int m=factor(x);
        v.push_back(s);
        while(m>1){
            next_permutation(s.begin(), s.end());
            v.push_back(s);
            m--;
        }
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
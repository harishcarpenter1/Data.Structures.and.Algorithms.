//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution{
public:
    void func(vector<int>&v,int N)
    {
        v.push_back(N);
        
        if(N<=0)
        {
            return;
        }
        
        func(v,N-5);
        v.push_back(N);
    }
    
    vector<int> pattern(int N)
    {
        vector<int>v;
        func(v,N);
        return v;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
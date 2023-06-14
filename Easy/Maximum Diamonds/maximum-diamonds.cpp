//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
  long long maxDiamonds(int A[], int N, int K) {
        // code here
        priority_queue<long long> p;
        for(long long i = 0;i< N;i++)
        {
            p.push(A[i]);
        }
        vector<long long> v;
        for(long long i =0 ;i< K;i++)
        {
            v.push_back(p.top());
            long long y = p.top();
            p.pop();
            y = y/2;
            p.push(y);
        }
        
        long long x = accumulate(v.begin(),v.end(),0LL);
        return x;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
       vector<int>arr;
        while(x){
            arr.push_back(x&1);
            x>>=1;
        }
        for(int i=arr.size();i<32;i++){
            arr.push_back(0);
        }
        long long ans=0;
        for(int i=31,j=0;i>=0;i--,j++){
            ans+=arr[j]*pow(2,i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
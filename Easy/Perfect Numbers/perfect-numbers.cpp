//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        long long sum = 1;
        if(N==1) return 0;
        for(long long i = sqrt(N); i>=2; i--){
            if(N%i == 0){
                sum += i;
                if(i != N/i){
                    sum+=N/i;
                }
            }
        }
        return sum == N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
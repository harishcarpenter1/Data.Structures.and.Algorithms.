//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if(n%2!=0) return false;
        
        vector<int>v(k,0);
        for(int i = 0; i<n; i++){
            v[nums[i]%k]++;
        }
        
        // [3, 5, 1, 3]
        // [0 1 0 3 0 1]
        
        for(int i = 0; i<k; i++){
            if(v[i]==0) continue;
            if(v[i]%2!=0 && i==0) return false; 
            else if(i>0  and v[i]!=v[k-i]) return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    vector<int> ans;
	    
	    vector<int> temp;
	    
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<n;i++){
            //using binary search for finding the index of ith element of original array
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            ans.push_back(index);
            //removing the element, so that the right-side for any ith element doesn't exist
            temp.erase(temp.begin()+index);
        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
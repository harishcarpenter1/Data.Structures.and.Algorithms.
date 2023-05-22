//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int mxidx = -1, prevones = 0, mxones = 0;
	    for(int i = 0; i<n; i++){
	        vector<int>row = arr[i];
	        int low = 0, high = m-1, mid;
	        while(low < high){
	            mid = (low+high)/2;
	            if(row[mid] == 1){
	                high = mid;
	            }
	            else{
	                low = mid+1;
	            }
	        }
	        
	        if(row[low] != 1){
	            prevones = 0;
	        }else{
	            prevones = m-low;
	        }
	        
	        if(prevones>mxones){
	            mxidx = i;
	            mxones = prevones;
	        }
	    }
	    return mxidx;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
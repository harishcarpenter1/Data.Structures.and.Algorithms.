//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
	    int lastocc = -1, firstocc = -1;
    
        // first occ
        int low = 0, high = n - 1, mid = low+(high-low)/2;
        
        while(low<=high){
            if(arr[mid] == x)
            {
               firstocc = mid;
               high = mid - 1;
            }
            else if(arr[mid]<x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            mid = low+(high-low)/2;
        }
        
        // last occurance
        low = 0;
        high = n - 1;
        mid = low+(high-low)/2;
        
        while(low<=high){
            if(arr[mid] == x)
            {
               lastocc = mid;
               low = mid + 1;
            }
            else if(arr[mid]<x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            mid = low+(high-low)/2;
        }
        
        if( lastocc == -1 && firstocc == -1) return 0;
        else if(lastocc == -1 || firstocc == -1) return 1;
        else return (lastocc-firstocc+1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
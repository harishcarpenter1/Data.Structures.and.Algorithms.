//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool check(int arr[], int n, int mid, int k){
        int cs = 1, sm = 0;
        for(int i = 0; i<n; i++){
            if(sm+arr[i]<=mid){
                sm+=arr[i];
            }else{
                sm = arr[i];
                cs++;
            }
        }
        return cs<=k;
    }
    int splitArray(int arr[] ,int n, int k) {
        int l = *max_element(arr,arr+n), sum = 0, mid;
        for(int i = 0; i<n; i++) sum+=arr[i];
        int r = sum;
        int ans = INT_MAX;
        while(l<=r){
            mid = (l+r)/2;
            if(check(arr, n, mid, k)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
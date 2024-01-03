//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool helper(int mid, int arr[], int n, int d){
        int currs=0;
        int cnt=1;
        for(int i = 0; i<n; i++){
            if(currs+arr[i]>mid){
                currs=arr[i];
                cnt++;
            }else{
                currs+=arr[i];
            }
        }
        if(cnt<=d) return true;
        return false;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        int mxel = arr[0];
        int ans = 0, high=0;
        for(int i = 0; i<n; i++){
            mxel=max(mxel,arr[i]);
            high+=arr[i];
        }
        int low = mxel, mid;
        while(low<=high){
            mid = low + (high-low)/2;
            if(helper(mid,arr,n,d)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends
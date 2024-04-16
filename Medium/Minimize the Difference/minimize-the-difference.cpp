//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int> pre_max(n),pre_min(n),suff_max(n),suff_min(n);
        pre_max[0] = arr[0],pre_min[0] = arr[0],suff_max[n-1] = arr[n-1],suff_min[n-1] = arr[n-1];
        for(int i = 1;i < n;i++){
            pre_max[i] = max(arr[i],pre_max[i-1]);
            pre_min[i] = min(arr[i],pre_min[i-1]);
            suff_max[n-1-i] = max(arr[n-1-i],suff_max[n-i]);
            suff_min[n-1-i] = min(arr[n-1-i],suff_min[n-i]);
        }
        int ans = INT_MAX;
        for(int i = 0;i <= n-k;i++){
            int mn = INT_MAX,mx = INT_MIN;
            if(i-1 >= 0) mn = min(mn,pre_min[i-1]),mx = max(mx,pre_max[i-1]);
            if(i+k < n) mn = min(mn,suff_min[i+k]),mx = max(mx,suff_max[i+k]);
            ans = min(ans,mx-mn);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
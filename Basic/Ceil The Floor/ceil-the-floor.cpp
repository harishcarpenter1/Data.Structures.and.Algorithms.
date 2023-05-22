//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    
    sort(arr,arr+n);
    
    int start=0,end=n-1,mid=start+(end-start)/2,floor=-1,ceil=-1;
    
    while(start <= end)
    {
        if(arr[mid] == x)
        {
            return {arr[mid],arr[mid]};
        }
        else if(arr[mid] < x)
        {
            floor = arr[mid];
            start = mid+1;
        }
        else{
            ceil=arr[mid];
            end=mid-1;
        }
        
        
       mid=start+(end-start)/2 ;
    }
    
    return {floor,ceil};
}
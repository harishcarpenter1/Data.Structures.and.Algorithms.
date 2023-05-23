//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int>ans;
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
    
    ans.push_back(firstocc);
    ans.push_back(lastocc);
    return ans;
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
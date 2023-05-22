//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int K)
    {
        
        int low = 0, high = N-1, mid = low+(high-low)/2;
        while(low<=high){
            if(Arr[mid] == K) return mid;
            else if(Arr[mid] > K) high = mid-1;
            else low = mid+1;
            mid=low+(high-low)/2;
        }
        return mid;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
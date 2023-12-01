//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
          int max_=0;
          int count=0;
          sort(arr,arr+n);
          sort(dep,dep+n);
          int i=0,j=0;
          while(i<n)
          {
              if(arr[i]<=dep[j]) 
              {
                  count++;
                  i++;
              }
              else
              {
                  count--;
                  j++;
              }
              max_=max(count,max_);
          }
          return max_;
   
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
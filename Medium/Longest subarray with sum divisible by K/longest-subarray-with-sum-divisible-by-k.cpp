//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum = 0, j = 0;
	    int res = 0;
	    unordered_map<int,int>mp;
	    while(j<n){
	        sum+=arr[j];
	        int r = sum%k;
	        if(r<0) r+=k;
	        if(r==0) res=max(res,j+1);
	        if(mp.find(r)!=mp.end()){
	            res=max(res,j-mp[r]);
	        }
	        else mp[r]=j;
	        j++;
	    }
	    return res;
	}
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends
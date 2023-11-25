//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1001
class Solution{
 
public:
void shuffleArray(int arr[],int n)
{
   for(int i=0;i<n/2;i++){
       arr[2*i]+=(arr[i]%mod)*mod;
       arr[2*i+1]+=(arr[i+n/2]%mod)*mod;
   }
   for(int i=0;i<n;i++){
       arr[i]/=mod;
   }
} 
 
};



//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
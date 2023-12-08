//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        bool isprime( int num)
    {  
        if(num==1) return 0;
        for( int i=2; i<= sqrt(num); i++)
        {
            if(num% i==0) return 0;
        }
        return 1;
    }
    
    int minNumber(int arr[],int N)
    {
        int sum=0;
        for( int i=0; i<N ; i++)
        {
            sum+=arr[i];
        }
        if(isprime(sum)) return 0;
        int num=1;
        while( 1)
        {
             int val= num+sum;
             if(isprime(val)) return num;
             else num++;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
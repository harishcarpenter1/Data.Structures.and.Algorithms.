//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long maxSum = INT_MIN;
        long sum = 0;
        for(int i = 0; i < K; i++) {
            sum += Arr[i];
        }
        maxSum = max(maxSum, sum);
        for(int i = 1; i <= N-K; i++) {
            sum += (Arr[K+i-1] - Arr[i-1]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
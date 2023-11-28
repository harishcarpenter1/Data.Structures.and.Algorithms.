//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kadaneminss(int arr[], int n){
        int minsum = arr[0];
        int currminsum = arr[0];
        for(int i = 1; i<n; i++){
            currminsum = min(currminsum+arr[i], arr[i]);
            minsum = min(minsum, currminsum);
        }
        return minsum;
    }
    int circularSubarraySum(int arr[], int num){
        int sum = 0;
        for(int i = 0; i<num; i++) sum+=arr[i];
        int mxsum = arr[0], currmx = arr[0];
        for(int i = 1; i<num; i++){
            currmx = max(currmx+arr[i], arr[i]);
            mxsum = max(mxsum, currmx);
        }
        int minss = kadaneminss(arr,num);
        if(mxsum>0) return max(mxsum, sum-minss);
        return mxsum;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
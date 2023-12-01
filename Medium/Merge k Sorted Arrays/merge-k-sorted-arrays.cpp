//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
     vector<int> merge(vector<int> A,vector<int> B,int K){
        vector<int> temp;
        int i=0,j=0;
        
        while(i<K && j<B.size()){
            if(A[i]<B[j])
                temp.push_back(A[i++]);
            else
                temp.push_back(B[j++]);
                
        }
        
        while(i<K){
            temp.push_back(A[i++]);        
        }
        
        while(j<B.size())
            temp.push_back(B[j++]);
        return temp;
    }
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> res=arr[0];
        
        for(int i=1;i<K;i++){
            res=merge(arr[i],res,K);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
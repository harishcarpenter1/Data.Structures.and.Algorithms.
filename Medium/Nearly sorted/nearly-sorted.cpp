//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        priority_queue<int> pq;
        vector<int> ans;
        for(int i=0; i<num; i++){
            pq.push(-arr[i]);
            
            if(pq.size()>K){
                int temp=pq.top();
                pq.pop();
                ans.push_back(-temp);
            }
        }
        
        while(!pq.empty()){
            int temp=pq.top();
            pq.pop();
            ans.push_back(-temp);
        }
        
        return ans;

}
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends
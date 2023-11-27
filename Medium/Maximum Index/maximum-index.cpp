//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int maxIndexDiff(int arr[], int N) 
    { 
        stack<int> st;
        st.push(N-1);
        for(int i=N-2;i>=0;i--)
        {
            if(arr[st.top()]<arr[i])
            {
                st.push(i);
            }
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(!st.empty()&&i>st.top())
            st.pop();
            while(!st.empty()&&arr[i]<=arr[st.top()]&&i<=st.top())
            {
                ans=max(ans,st.top()-i);
                st.pop();
            }
        }
        return ans;
    }
};




//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
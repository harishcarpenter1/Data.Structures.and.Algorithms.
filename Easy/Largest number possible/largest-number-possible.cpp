//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string ans = "";
        int no_of_nines = S/9;
        int rem = S % 9;
        
        if (9*N<S || (S == 0 && N != 1)) 
            return "-1";
        
        for(int i = 0; i<no_of_nines; i++){
            ans += '9';
        }
        
        N = N - no_of_nines;
        
        if(rem != 0){
            ans  = ans + char(rem+'0');
            N--;
        }
        
        while(N>0){
            ans  = ans + '0';
            N--;
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
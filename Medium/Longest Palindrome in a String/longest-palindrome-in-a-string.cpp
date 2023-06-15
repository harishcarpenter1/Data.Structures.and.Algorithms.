//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        
        int maxl = 1 ;
        int start  = 0 ;
        int end  = 0 ;
        int n = S.size()  ;
        
        for( int i = 0 ; i < n ; i++ )
        {
            
            // checking for odd length palindromes 
            
            int prev = i - 1 ;
            int nxt =  i + 1 ;
           
            while( prev >= 0 && nxt < n && S[prev] == S[nxt] )
            {
                prev-- ;
                nxt++  ;
                
            }
            
            int length = nxt - prev - 1 ;
            
            if( length > maxl )
            {
                maxl = length ;
                start = prev + 1 ;
            }
            else if( length == maxl && prev + 1 < start )
            {
                maxl = length ;
                start = prev + 1 ;
            }
            
            
            
            // checking for even length palindromes
            
             prev = i  ;
             nxt =  i + 1 ;
             
            while( prev >= 0 && nxt < n && S[prev] == S[nxt] )
            {
                prev-- ;
                nxt++  ;
            }
            
            length = 0 ;
            length = nxt - prev - 1 ;
            
            if( length > maxl )
            {
                maxl = length ;
                start = prev + 1 ;
            }
            else if( length == maxl && prev + 1 < start )
            {
                maxl = length ;
                start = prev + 1 ;
            }
            
            
            
        }
        
        return S.substr( start , maxl ) ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
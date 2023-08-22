//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int max_sum = 0, ans = 0;
        
        for(int i = 0; i<n; i++){
            int rs = 0, cs = 0;
            for(int j = 0; j<n; j++){
                rs += matrix[i][j];
                cs += matrix[j][i];
            }
            max_sum = max(rs, max_sum);
            max_sum = max(cs, max_sum);
        }
        
        for(int i = 0; i<n; i++){
            int rs = 0;
            for(int j = 0; j<n; j++){
                rs += matrix[i][j];
            }
            
            ans += (max_sum - rs);
        }
        
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
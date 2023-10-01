//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        if(n==1){
            return matrix[0];
        }
        if(m==1){
            vector<int> tmp;
            for(int i=0;i<n;i++){
                tmp.push_back(matrix[i][0]);
            }
            return tmp;
        }
        vector<int> ans;
        int l=0;
        int r=m-1;
        int u=0;
        int d=n-1;
        int i=0;
        while(i<4){
            if(i%4==0){
                for(int j=l;j<=r;j++){
                    ans.push_back(matrix[u][j]);
                }
                u++;
                
            }
            else if(i%4==1){
                for(int j=u;j<=d;j++){
                    ans.push_back(matrix[j][r]);
                }
                r--;
            }
            else if(i%4==2){
                for(int j=r;j>=l;j--){
                    ans.push_back(matrix[d][j]);
                }
                d--;
            }
            else{
                for(int j=d;j>=u;j--){
                    ans.push_back(matrix[j][l]);
                }
                l++;
            }
            i++;
        }
        return ans;
    }


};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
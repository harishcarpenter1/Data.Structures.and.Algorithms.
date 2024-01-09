//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int i = 0, m = txt.size(), n = pat.size();
            vector<int>ans;
            while(i<m){
                if(pat[0]==txt[i]){
                    int j = 0, st = i;
                    while(i<m && j<n){
                        if(pat[j]!=txt[i]){
                            break;
                        }
                        i++;
                        j++;
                    }
                    if(j==n){
                        ans.push_back(st+1);
                    }
                    i = st+1;
                }else{
                    i++;
                }
            }
            if(ans.size()==0) return {-1};
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
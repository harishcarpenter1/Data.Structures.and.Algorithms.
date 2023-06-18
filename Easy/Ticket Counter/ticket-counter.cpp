//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        deque<int> q;
        
        for(int i=1;i<=n;i++)
        {
            q.push_back(i);
        }
        int flag=0;
        while(n>k)
        {
            if(flag==0)
            {
                for(int a=0;a<k;a++)
                {
                    q.pop_front();
                }
                flag=1;
            }
            else
            {
                for(int a=0;a<k;a++)
                {
                    q.pop_back();
                }
                flag=0;
            }
            n-=k;
        }
        return flag==0?q.back():q.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
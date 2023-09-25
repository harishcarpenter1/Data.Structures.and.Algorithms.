//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int k, vector<int> &A, vector<int> &B) {
        
        priority_queue<int, vector<int>, greater<int> >pq;
        vector<int>ans;
        
        sort(A.begin(),A.end(), greater<int>());
        sort(B.begin(),B.end(), greater<int>());
        
        for(int i = 0; i<A.size(); i++){
            for(int j = 0; j<B.size(); j++){
                int sum = A[i] + B[j];
                if(pq.empty() || pq.size() < k){
                    pq.push(sum);
                }else{
                    if(pq.top() < sum){
                        pq.pop();
                        pq.push(sum);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
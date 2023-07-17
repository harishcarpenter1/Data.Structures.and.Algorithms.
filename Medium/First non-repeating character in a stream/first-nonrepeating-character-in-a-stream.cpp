//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {

 public:

  string FirstNonRepeating(string A){

      // Code here

      string ans = string(1,A[0]);

      vector<int> temp(26,0);

      temp[A[0]-'a']++;

      int i=0,j=1,n=A.size();

      while(j<n){

          temp[A[j]-'a']++;

          j++;

          while(temp[A[i]-'a']!=1 && i<j){

              i++;

          }

          if(i==j)ans+="#";

          else ans+=A[i];

      }

      return ans;

  }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
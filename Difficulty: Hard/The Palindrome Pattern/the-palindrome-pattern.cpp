//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool checkPalindrome(vector<int>& vec) {
        int left = 0;
        int right = vec.size() - 1;
        while (left < right) {
            if (vec[left] != vec[right]) return false;
            left++;
            right--;
        }
        return true;
    }


    string pattern(vector<vector<int>> &arr) {
        string ans="";
        
        for (int i = 0; i < arr.size(); i++) {
            if (checkPalindrome(arr[i])) {
                ans = to_string(i) + " R"; 
                return ans;
            }
        }
        for (int j = 0; j < arr[0].size(); j++) {
            vector<int> column;
            for (int i = 0; i < arr.size(); i++) {
                column.push_back(arr[i][j]);
            }
            if (checkPalindrome(column)) {
                ans = to_string(j) + " C"; 
                return ans;
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
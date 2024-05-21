//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first == b.first) {
                return a.second > b.second; // If first elements are equal, sort by second element in descending order
            }
            return a.first < b.first; // Otherwise, sort by first element
        }
    };
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        multiset<pair<int, int>, Compare> s;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            pair<int, int> p = make_pair(abs(x - arr[i]), arr[i]);
            s.insert(p);
        }
        for (const auto& p : s) {
            if(p.second == x)
                continue;
            if(k > 0) {
                ans.push_back(p.second);
                k--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
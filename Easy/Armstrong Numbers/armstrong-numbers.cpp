//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string armstrongNumber(int n) {
        // Convert number to string to find the number of digits
        string a = to_string(n);
        int m = a.length();
        int sum = 0;

        // Calculate the sum of the cubes of the digits
        for (int i = 0; i < m; i++) {
            int digit = a[i] - '0'; // Convert character to integer
            sum += pow(digit, 3);
        }

        // Check if the sum is equal to the original number
        if (sum == n)
            return "true";
        else
            return "false";
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
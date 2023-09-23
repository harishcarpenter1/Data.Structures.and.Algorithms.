//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    int start = 0;
    int end = n - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        long long sum1 = 0, sum2 = 0;

        for (int i = 0; i < mid; i++) {
            sum1 += a[i];
        }

        for (int j = n - 1; j > mid; j--) {
            sum2 += a[j];
        }

        if (sum1 == sum2) {
            return mid + 1;  // Return 1-based index
        }

        if (sum1 > sum2) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return -1;
}

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i =0;
        int count = 0;
        while(i<n)
        {
            if(a[i] < k)
            {
                count++;
            }
            
            long product = a[i];
            int j = i+1;
            while(j<n && product < k)
            {
                product = product*a[j];
                if(product < k)
                {
                    count++;
                    j++;
                }
                
            }
            i++;
            
        }
        return count;


    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
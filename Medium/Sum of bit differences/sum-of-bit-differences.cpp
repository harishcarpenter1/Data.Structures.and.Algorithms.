//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:
/*
	int countDifferingBits(int a, int b) {

        int xor_res = a^b;
        int count = 0;
        while(xor_res){
            count += xor_res & 1;
            xor_res >>= 1;
        }
        
        --------------- or -------------

        bitset<32> bits(a ^ b);
        return bits.count();
    }
*/
	long long sumBitDifferences(int arr[], int n) {
	    long long ans = 0;
	    // 32 bits max
	    // here arr[i] <= 10^5 so max bits log2(10^5) = 16.61
	    // hence max 17 bits
	    // traverse for every bit
	    for(int i = 0; i<17; i++){
	        // count set bits for each number at ith position
	        long long cntset = 0;
	        // every number
	        for(int j = 0; j<n; j++){
	            // if ith bit of arr[j] is set 
	            if(arr[j]%2==1){
	                cntset++;
	            }
	            // right shift the arr[j]th number 
	            // arr[j]/=2;
	            arr[j] >>= 1;
	        }
	        // formula to count the pairs - no. of set bits * no of unset bits * 2
	        ans += cntset*(n-cntset)*2;
	        
	    }
	    return ans;
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        int n = wordList.size();
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        q.push({startWord, 1});
        st.erase(startWord);
        
        while(!q.empty()){
            string w = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if(w == targetWord) return steps;
            
            for(int i = 0; i<w.size(); i++){
                char ch = w[i];
                for(char cc = 'a'; cc<= 'z'; cc++){
                    w[i] = cc;
                    if(st.find(w) != st.end()){
                        st.erase(w);
                        q.push({w,steps+1});
                    }
                }
                w[i] = ch;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
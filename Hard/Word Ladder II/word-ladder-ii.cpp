//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string s, string t, vector<string>& ls) {
        queue<vector<string>>q;
        vector<vector<string>>ans;
        unordered_set<string>st;
        for(auto it:ls) st.insert(it);
        vector<string>used;
        used.push_back(s);
        q.push({s});
        int level = 0;
        while(!q.empty()){
            vector<string>v1 = q.front();
            q.pop();
            if(v1.size()>level){
                level++;
                for(auto it:used){    
                    st.erase(it);
                }
                used.clear();
            }
            string temp = v1.back();
            if(temp==t){
                if(ans.size()==0){
                    ans.push_back(v1);
                }else if(ans[0].size()==v1.size()){
                    ans.push_back(v1);
                }
            }
            for(int i = 0; i<temp.size(); i++){
                char orignal = temp[i];
                for(char j = 'a'; j<='z'; j++){
                    temp[i]=j;
                    if(st.count(temp)>0){
                        v1.push_back(temp);
                        q.push(v1);
                        used.push_back(temp);
                        v1.pop_back();
                    }
                }
                temp[i]=orignal;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends
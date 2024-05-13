//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  void dfs(map<int,list<int>>&adj_list,vector<int>&visited,int i,int &ct1,int &ct2){
      visited[i]=1;
      ct1++;
      for(auto it:adj_list[i]){
          ct2++;
          if(!visited[it]){
              dfs(adj_list,visited,it,ct1,ct2);
          }
      }
  }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
       vector<int>visited(v+1,0);
       map<int,list<int>>adj_list;
       for(auto it:edges){
           adj_list[it[0]].push_back(it[1]);
           adj_list[it[1]].push_back(it[0]);
       }
       int ans=0;
       for(int i=1;i<=v;i++){
           if(!visited[i]){
               int ct1=0;
               int ct2=0;
               dfs(adj_list,visited,i,ct1,ct2);
               
               if((ct1*(ct1-1))==ct2)ans++;
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends
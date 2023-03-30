//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void solve(int col, int n, vector<int> &left,vector<int>&ld ,vector<vector<int>>&ans, vector<int>&ud,vector<int>&board){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0 ; row<n;row++){
        if(left[row]==0 and ld[row+col]==0 and ud[(n-1)+(col-row)]==0){
            board[row]=col+1;
            left[row]=1;
            ld[row+col]=1;
            ud[(n-1)+(col-row)]=1;
            solve(col+1,n,left,ld,ans,ud,board);
            ud[(n-1)+(col-row)]=0;
            ld[row+col]=0;
            left[row]=0;
        }
    }
}
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> left(n,0);
        vector<int> board(n,0);
        vector<int> ud(2*n-1,0);
         vector<int> ld(2*n-1,0);
         solve(0,n,left,ld,ans,ud,board);
         sort(ans.begin(),ans.end());
         return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
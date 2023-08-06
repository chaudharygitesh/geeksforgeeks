//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    string sw(string s,int a, int b){
        char temp = s[a];
        s[a]=s[b];
        s[b] = temp;
        return s;
        
    }
    void solve(string s, int l, int r, vector<string> &ans){
        if(l==r){
            ans.push_back(s);
            return;
        }
        for(int i=l;i<=r;i++){
            s = sw(s,l,i);
            solve(s,l+1,r,ans);
            s = sw(s,l,i);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
         vector<string> ans;
        solve(S,0,S.size()-1,ans);
        sort(ans.begin(),ans.end());
        return ans;
    
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
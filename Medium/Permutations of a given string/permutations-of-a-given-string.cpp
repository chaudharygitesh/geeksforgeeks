//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	set<string> st;
	void h(int ind, string s, vector<string> &ans ){
	    if(ind==s.size()){
	        if(st.find(s)==st.end()){
	            st.insert(s);
	            ans.push_back(s);
	        }
	        
	        return;
	    }
	    for(int i = ind;i<s.size();i++){
	        swap(s[i],s[ind]);
	        h(ind+1,s,ans);
	        swap(s[i],s[ind]);
	        
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    
		     vector<string> ans;
		     string st="";
		     h(0,S,ans);
		     sort(ans.begin(),ans.end());
		     return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
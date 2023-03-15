//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	set<string>st;
	void h(string &ds,string &nums, vector<string> &ans, int freq[]){
         
	    if(nums.length()==ds.length()){
	        if(st.find(ds)==st.end()){
	              ans.push_back(ds);
	              st.insert(ds);
	        }
	     
	       

	        return;
	    }
	    for(int i = 0 ; i<nums.size();i++){
	        if(!freq[i]){
	         ds.push_back(nums[i]);
	            freq[i]=1;
	            h(ds,nums,ans,freq);
	            freq[i]=0;
	            ds.pop_back();
	        }
	    }
	}
		vector<string>find_permutation(string S)
		{
		    int freq[S.length()];
		    for(int i=0;i<S.length();i++)freq[i]=0;
		    vector<string> ans;
		    string st="";
		    h(st,S,ans,freq);
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
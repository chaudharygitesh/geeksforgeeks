//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        // set<int> s;
        int n=nums.size();
        // for(int i = 0 ; i< n;i++){
        //     s.insert(nums[i]);
        // }
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int i = 0; 
       while(i<n){
            if(nums[i]==nums[i+1]){
                i=i+2;
            }
            else if(nums[i]!=nums[i+1]){
                ans.push_back(nums[i]);
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
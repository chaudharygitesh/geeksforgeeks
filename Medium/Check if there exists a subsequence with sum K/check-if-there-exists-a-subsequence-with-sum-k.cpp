//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool s(int i ,vector<int> &arr,int &k, int n,int sum){
        if(k<sum){
            return false;
        }
        if(i==n){
            if(k==sum){
                return true;
            }
            else return false;
        }
        sum+=arr[i];
        if( s(i+1,arr,k,n,sum))return true;
        sum-=arr[i];
        if (s(i+1,arr,k,n,sum))return true;
        
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        s(0,arr,k,n,0);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends
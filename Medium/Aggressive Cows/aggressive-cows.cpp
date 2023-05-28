//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
bool isposible(vector<int> &stalls,int n,int k,int mid){
    int cor=stalls[0];int cnt=1;
    for(int i =0; i<n;i++){
        if(stalls[i]-cor>=mid){
            cnt++;
           
            cor=stalls[i];
        }
          if(cnt==k){
        return true;
    }
       
    }
    return false;
    
}

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int l=0;int h=stalls[n-1];
        int ans=-1;
        int mid=0;
        while(l<=h){
            mid=l+(h-l)/2;
            if(isposible(stalls,n,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
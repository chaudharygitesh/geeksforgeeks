//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        
        unordered_map<int,bool>mp;
        
        for(int i=1;i<=leaves;i++)
        {
            mp[i] = false;
        }
        
        for(int i=0;i<n;i++){
            if(frogs[i] <= leaves and mp[frogs[i]] == false){


            for(int j=frogs[i];j<=leaves;j+=frogs[i]){
                    mp[j] = true;
            }
          }
        }
        int c = 0;
        for(auto it:mp)
        {
            if(it.second == false)
            c++;
        }
        return c;
       
   }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
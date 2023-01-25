//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
      int n = s.length();
        string temp = "";
        int cnt = 0;
        for(int i=0;i<n;i++){
            temp += s[i];
            if((2*i+1) < n && (temp == s.substr(i+1, i+1))){
                cnt = i;
            }
        }
        return (n-cnt);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
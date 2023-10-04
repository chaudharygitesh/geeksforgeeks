//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here  
          int n = str.length();
        int arr[n];
        for(int i = 0 ; i < n ; i++)
        {
            if(str[i]=='I')
                arr[i]=1;
            else if(str[i]=='V')
                    arr[i]= 5 ;
            else if(str[i]=='X')
                    arr[i]= 10 ;
            else if(str[i]=='L')
                    arr[i]= 50 ;
            else if(str[i]=='C')
                    arr[i]= 100;
            else if(str[i]=='D')
                    arr[i]= 500;
            else if(str[i]=='M')
                    arr[i]= 1000;
        }
        int ans = 0;
        for(int i = 0 ; i < n-1 ; i++)
        {
            if(arr[i+1] <= arr[i])
            {
                ans+=arr[i];
            }
            else
            {
                ans-=arr[i];
            }
        }
        ans+=arr[n-1];
        return ans;
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
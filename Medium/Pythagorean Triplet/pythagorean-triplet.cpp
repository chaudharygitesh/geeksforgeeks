//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	  bool checkTriplet(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]*arr[i];
        }
        for(int i=0;i<n;i++)
        {
            int j=0,k=i-1;
            while(j<k)
            {
                if(arr[j]+arr[k]==arr[i])
                {
                    return 1;
                }
                else if(arr[j]+arr[k]<arr[i])
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends
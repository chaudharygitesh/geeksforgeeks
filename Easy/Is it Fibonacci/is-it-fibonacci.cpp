//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
          
        if(K >= N){
            return GeekNum[N-1];
        }
        
        long long sum = 0;
        int n = GeekNum.size();
        int i = n-1;                                // i = 2
        for(i ; i >= n-K ;i--){                     // i >= n-k --> i >= 0
            sum += GeekNum[i];
        }
        //i = -1
        i++;                                        // sum = 3 , i = 0
        GeekNum.push_back(sum);
        int a = N - n -1;                           // a = 5 - 3 - 1 --> a = 1
        while(a != 0){                              // 0 1 2 3
            sum += GeekNum.back();                  // sum = 3 + 3 = 6
            sum -= GeekNum[i];                      // sum = 6 - 0 = 6
            i++;
            a--;
            GeekNum.push_back(sum);                 // 0 1 2 3 6
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
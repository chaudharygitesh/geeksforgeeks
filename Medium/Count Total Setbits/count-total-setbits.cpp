//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long solve( long long n){
        if(n==0)
        return 0;
        
        long long ans=0, x=(long long)log2(n);
        long long upto2= x*(pow(2,x-1));
        long long msb= n-pow(2,x)+1;
        
        long long rest= n-pow(2,x);
        
        ans+= upto2+ msb + solve(rest);
        
        return ans;
    }
 
    long long countBits(long long N) {
        return solve(N);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    long long mod = 1000000007;
    long long power(int n,int r)
    {
       //Your code here
       if(r==1){
           return n;
       }
       long long x = power(n , r/2);
       x = (x*x)%mod;
       if(r%2 != 0){
           return (n*x)%mod;
       }
       return x%mod;
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends
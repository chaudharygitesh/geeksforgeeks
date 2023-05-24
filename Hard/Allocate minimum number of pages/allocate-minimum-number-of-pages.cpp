//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int isp(int A[],int mid,int M,int N){
        int cnt = 0;
        int sumAllocated = 0;
        for (int i = 0; i < N; i++) {
            if (sumAllocated + A[i] > mid) {
              cnt++;
              sumAllocated = A[i];
              if (sumAllocated > mid) return false;
            } else {
                sumAllocated += A[i];
        }
    }
    if(cnt<M)return true;
    return false;
}
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N)return -1;
        int l=A[0];
        int h=0;
        for(int i=0;i<N;i++){
            h+=A[i];
            l=min(l,A[i]);
        }
        while(l<=h){
            int mid=(l+h)>>1;
            if(isp(A,mid,M,N)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
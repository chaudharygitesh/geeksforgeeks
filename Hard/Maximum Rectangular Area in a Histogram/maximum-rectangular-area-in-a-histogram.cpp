//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
      vector<long long> nextsmallele(long long arr[],int n){
         stack<long long> s;
        s.push(-1);
        vector<long long> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            long long curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<long long> prevsmallele(long long arr[],int n){
         stack<long long> s;
        s.push(-1);
        vector<long long> ans(n);

        for(int i=0;i<n;i++) {
            long long curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        long long area=INT_MIN;
        vector<long long> next=nextsmallele(arr,n);
        vector<long long> prev=prevsmallele(arr,n);
        for(long long i = 0 ;i< n ;i++){
            long long l =arr[i];
            if(next[i]==-1){
                next[i]=n;
            }
            long long b=next[i]-prev[i]-1;
            long long newarea=l*b;
            area=max(area,newarea);
            
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
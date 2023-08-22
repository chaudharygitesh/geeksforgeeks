//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
           vector<int>rows;
        vector<int>columns;
        int sum,rowMax=INT_MIN,columnMax=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[i][j];
            }
            if(sum>=rowMax)
            rowMax=sum;
            rows.push_back(sum);
        }
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[j][i];
            }
            if(sum>=columnMax)
            columnMax=sum;
            columns.push_back(sum);
        }
        
        int maxi=max(rowMax,columnMax);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=maxi-rows[i];
        }
        return ans;
        
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
         int s=0;
        int q=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='-' || str[i]=='+'){
                q++;
                if(q>1)
                return -1;
                if(s>0)
                return -1;
            }
            else if((str[i]-'0')>9){
                return -1;
            }
            else{
                s=10*s+str[i]-'0';
            }
        }
        if(q==0)
        return s;
        else
        return -s;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
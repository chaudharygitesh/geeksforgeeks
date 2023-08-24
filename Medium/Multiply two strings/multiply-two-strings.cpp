//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       if(s1=="0" or s2=="0") return "0";
       if(s1[0]=='-' and s2[0]!='-') cout<<"-";
       if(s1[0]!='-' and s2[0]=='-') cout<<"-";
       if(s1[0]=='-') s1 = s1.substr(1);
       if(s2[0]=='-') s2 = s2.substr(1);
       
       int carry=0,f=0,k=0,prd;
       int n = s1.size(),m = s2.size();
       vector<int> vec(n+m,0);
       string ans="";
       
       for(int i=n-1;i>=0;i--){
           int a = s1[i]-'0';
           k = 0;
           carry = 0;
           for(int j=m-1;j>=0;j--){
               int b = s2[j]-'0';
               prd = (a*b) + carry + vec[f+k];
               carry = prd/10;
               vec[f+k] = prd%10;
               k++;
           }
           if(carry>0){
               vec[f+k]+=carry;
           }
           f++;
       }
       int size = vec.size()-1;
       while(size>0 and vec[size]==0) size--;
       while(size>=0){
           ans+=std::to_string(vec[size]);
           size--;
       }
       return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends
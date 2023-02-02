//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool saveIronman(string ch);


int main()
{
    int t,b,c,d,e,f,g,h;
    cin>>t;
    char cc;
    cc = getchar();
    
    while(t--)
    {
        string ch;
        getline(cin,ch);
        
        if(saveIronman(ch)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }
}

// } Driver Code Ends



bool saveIronman(string ch)
{
    // Complete the function
   int start=0 , size1= ch.size(),  end=size1-1;
    while(start < end)
     {
           while(!(ch[start] >=65 && ch[start] <=90 ) && !(ch[start] >=97 && ch[start] <=122 ) && !(ch[start] >=48 && ch[start] <=57 ))
            start++;
        while(!(ch[end] >=65 && ch[end] <=90 ) && !(ch[end] >=97 && ch[end] <=122 )  && !(ch[end] >=48 && ch[end] <=57))
            end--;
         if(start<end && tolower(ch[start]) != tolower(ch[end])) return 0;
         start++, end--;       
     }
    return 1;   
    
}

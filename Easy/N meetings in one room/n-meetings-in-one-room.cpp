//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    struct meet{
        int s;
        int e;
        int pos;
    };
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(struct meet m1,meet m2){
        if(m1.e<m2.e)return true;
        else if(m1.e>m2.e)return false;
        else if(m1.pos<m2.pos)return true;
        return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meet m[n];
        for(int i = 0 ; i < n ; i++){
            m[i].s=start[i];
            m[i].e=end[i];
            m[i].pos=i+1;
        }
        sort(m,m+n,comp);
        int cnt=1;
        int limit=m[0].e;
        for(int i = 0 ; i <n;i++){
            if(m[i].s>limit){
                limit=m[i].e;
                cnt++;
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
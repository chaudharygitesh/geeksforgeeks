//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<int> leftgreater(int arr[],int n){
    vector<int> ans(n);
    int currentg;
    int maxi=INT_MIN;
    ans[0]=-1;
    int k=1;
    for(int i=0;i<n-1;i++){
        currentg=arr[i];
        maxi=max(currentg,maxi);
        ans[k]=maxi;
        k++;
    }
    return ans;
    
}
vector<int> rightsmaller(int arr[],int n){
    vector<int> ans(n);
    int currentm;
    int mini=INT_MAX;
    ans[n-1]=-1;
    int k=n-2;
    for(int i=n-1;i>0;i--){
    currentm=arr[i];
        mini=min(currentm,mini);
        ans[k]=mini;
        k--;
    }
    return ans;
    
}
int findElement(int arr[], int n) {
    vector<int> ans1;
    vector<int> ans2;
    ans1=leftgreater(arr,n);
    ans2=rightsmaller(arr,n);
    for(int i=1;i<n-1;i++){
        if(ans1[i]<=arr[i] && arr[i]<=ans2[i]){
            return arr[i];
        }
    }
    return -1;
}
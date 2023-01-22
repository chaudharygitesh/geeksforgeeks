//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void findParent(Node* root,unordered_map<Node*,Node*>&parents){
      if(root==NULL)return;
      queue<Node*>q;
      q.push(root);
      while(!q.empty()){
          Node* curr=q.front();
          q.pop();
          if(curr->left){
              parents[curr->left]=curr;
              q.push(curr->left);
              
          }
          if(curr->right){
              parents[curr->right]=curr;
              q.push(curr->right);
              
          }
      }
      
      
  }
      Node* findTarget(Node* root, int target){
      if(root==NULL)return NULL;
      if(root->data==target)return root;
         Node *leftAns=findTarget(root->left,target);

        Node *rightAns=findTarget(root->right,target);

        if(!leftAns && !rightAns) return NULL;

        if(leftAns && !rightAns) return leftAns;

        if(rightAns && !leftAns) return rightAns;
  }
      int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>parents;
        findParent(root,parents);
        
        unordered_map<Node*,bool>visited;
        Node* t=findTarget(root,target);
        queue<Node*>q;
        visited[t]=true;
        q.push(t);
        int mtime=0;
        while(!q.empty()){
            int size=q.size();
            mtime++;
            for(int i=0;i<size;i++){
                Node* curr=q.front();
                q.pop();
                if(curr->left and !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                    
                }
                if(curr->right and !visited[curr->right]){
                     q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parents[curr] and !visited[parents[curr]]){
                    q.push(parents[curr]);
                    visited[parents[curr]]=true;
                }
                
            }
            
        }
        return mtime-1;
    }

};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
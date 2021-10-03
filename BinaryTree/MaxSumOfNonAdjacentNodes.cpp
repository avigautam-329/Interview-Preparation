#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    
    int helperFunction(Node* root, unordered_map<Node* , int> &dp){
        if(root == NULL){
            return 0;
        }
        
        if(dp.find(root) != dp.end()){
            return dp[root];
        }
        
        // Now we have 2 choices to make.
        int inclusionSum = root->data;
        if(root->left != NULL){
            inclusionSum += helperFunction(root->left->left , dp);
            inclusionSum += helperFunction(root->left->right , dp);
        }
        
        if(root->right != NULL){
            inclusionSum += helperFunction(root->right->left , dp);
            inclusionSum += helperFunction(root->right->right , dp);
        }
        
        // Then we choose the second option of exclusion.
        int exclusionSum = helperFunction(root->left , dp) + helperFunction(root->right , dp);
        
        dp[root] = max(inclusionSum , exclusionSum);
        
        return dp[root];
    }
    
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    
    //Approach:
    /*
        1. This is solved using a dynamic programming approach,
        2. Each node has the choice of being included or excluded from the sum.
        3. Soo if the node is included, we have 4 choices that can be made.
        4. If not, then we use the root->left and root->right nodes to create the exclusion sum.
        5. Our final answer will be at the initial root position in the hashmap. 
    */
    int getMaxSum(Node *root) 
    {
        
        if(root == NULL){
            return 0;
        }
        
        // Instead of using an array, we will use an unordered map to store the max sum obtained
        // by making the the 2 choices for each node.
        unordered_map<Node* , int> maxSumFromNode;
        
        int maxSum = helperFunction(root , maxSumFromNode);
        
        return maxSum;
    }
};

// { Driver Code Starts.

// Driver code 
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  }
  return 0;
}  // } Driver Code Ends

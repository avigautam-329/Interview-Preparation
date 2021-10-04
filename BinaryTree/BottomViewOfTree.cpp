#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


vector <int> bottomView(Node *root);

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
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
  	
  	// Approach
  	
  	/*
		1. It has the same intuition as the top view of binary tree.
		2. But in this case, we need the last occurence of a node at a position in the vertical line that we are trying to imagine.
		3. Hence we just at each step if a node exists on a place at the number line, we replace it with the curr Node if it lies on the same number on the number line.  
	*/
  	
  	
    vector <int> bottomView(Node *root) {
        queue<pair<Node* , int>> pendingNodes;
        pendingNodes.push({root , 0});
        
        map<int , int> finalView;
        finalView[0] = root->data;
        
        while(!pendingNodes.empty()){
            Node* currNode = pendingNodes.front().first;
            int verticalHeight = pendingNodes.front().second;
            
            pendingNodes.pop();
            
            if(currNode->left != NULL){
                finalView[verticalHeight - 1] = currNode->left->data;
            
                pendingNodes.push({currNode->left , verticalHeight - 1});
                
            }
            
            if(currNode->right != NULL){
                finalView[verticalHeight + 1] = currNode->right->data;
                
                pendingNodes.push({currNode->right , verticalHeight + 1});
            }
        
        }
        
        vector<int> ans;
        for(auto x:finalView){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


  // } Driver Code Ends

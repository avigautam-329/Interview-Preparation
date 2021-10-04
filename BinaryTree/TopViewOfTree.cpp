#include <bits/stdc++.h>
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    
    
    // The following approach is for Time Complexity O(NlogN).
    // The approach is:
    /*
		1. Imagine a horizontal number line, out root node is at 0 and as we move left we move one place in negative direction.
		2. If we move to the right, we move one place in the positive direction.
		3. We will use a map to store the vertical number position and the first node that appeared at that number.
		4. We will use a level order traversal, hence our queue will not just store a node, but will also store its position on the vertical line.
		5. Hence the data type of the queue will be of pair type.
		6. In this question, we only need to look at the first occurence at of node at a specific distance from the root node, as we are viewing the tree from the top.
	*/
    vector<int> topView(Node *root)
    {
        queue<pair<Node* , int>> pendingNodes;
        pendingNodes.push({root , 0});
        
        map<int , int> finalView;
        finalView[0] = root->data;
        
        while(!pendingNodes.empty()){
            // We will look at each node individually.
            Node* currNode = pendingNodes.front().first;
            int verticalHeight = pendingNodes.front().second;
            
            pendingNodes.pop();
            
            if(currNode->left != NULL){
                if(finalView.find(verticalHeight - 1) == finalView.end()){
                    finalView[verticalHeight - 1] = currNode->left->data;
                }
                
                pendingNodes.push({currNode->left , verticalHeight - 1});
            }
            
            if(currNode->right != NULL){
                if(finalView.find(verticalHeight + 1) == finalView.end()){
                    finalView[verticalHeight + 1] = currNode->right->data;
                }
                
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
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends

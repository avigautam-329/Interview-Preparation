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


vector<int> diagonal(Node *root);

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

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
   // THE CONCEPT IS TO KEEP A QUEUE FOR THE LEFT TREE NODE OF THE CURR NODE.
   // By doing this for each node we will go to the right till we don't hit a null address space.
   // As soon as we hit a null address space we will go to the first left node that we saved in the queue.
   
   queue<Node*> pendingLeftNodes;
   
   // We will store the first root node in the queue and also we will store the value of root in the answer vector.
    pendingLeftNodes.push(root);  
   vector<int> ans;
   
   while(!pendingLeftNodes.empty()){
       Node* currNode = pendingLeftNodes.front();
       pendingLeftNodes.pop();
       
       while(currNode != NULL){
           // We wil check if the currNode has a left node or not.
           // If yes, we will put it into the queue.
           if(currNode->left != NULL){
               pendingLeftNodes.push(currNode->left);

           }
           
            ans.push_back(currNode->data);
               
            // By doing this, we will move to the right as much as possible.
            currNode = currNode->right;
       }
   }
   
   return ans;
   
}

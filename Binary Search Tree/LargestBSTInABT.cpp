#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class BSTConditions{
  public:
    bool isBST;
    int size;
    int minimum;
    int maximum;
};


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    // Approach:
    
    // To complete this question we need to have a bottom up aproach.
    // This means that we will start out iduction steps from the leaf nodes.
    // Each leaf node is a BST in itself.
    // But for nodes which are not leaf nodes, we need to get its left and right subtress values and constraints.
    
    BSTConditions findBST(Node* root){
        if(root == NULL){
            BSTConditions temp;
            temp.isBST = true;
            temp.size = 0;
            temp.minimum = INT_MAX;
            temp.maximum = INT_MIN;
            
            return temp;
        }
        
        if(root->left == NULL && root->right == NULL){
            BSTConditions temp;
            temp.isBST = true;
            temp.size = 1;
            temp.minimum = root->data;
            temp.maximum = root->data;
            
            return temp;
        }
        
        BSTConditions leftSubTree = findBST(root->left);
        BSTConditions rightSubTree = findBST(root->right);
        
        if(leftSubTree.isBST && rightSubTree.isBST){
            if(root->data > leftSubTree.maximum && root->data < rightSubTree.minimum){
                BSTConditions res;
                res.isBST = true;
                res.size = leftSubTree.size + rightSubTree.size + 1;
                res.minimum = leftSubTree.minimum;
                res.maximum = rightSubTree.maximum;
                
                
                // These conditions are very important for cases where for a parent node.
                //  - The left Node is null and right is not and vica versa.
                //
                if(res.minimum == INT_MAX){
                    res.minimum = root->data;
                }
                if(res.maximum == INT_MIN){
                    res.maximum = root->data;
                }

                return res;
            }
        }
        
        BSTConditions res;
        res.isBST = false;
        res.size = max(leftSubTree.size , rightSubTree.size);
        res.minimum = res.maximum = 0;
        
        return res;
    } 
    
    int largestBst(Node *root)
    {
        BSTConditions maxBST = findBST(root);
        
        return maxBST.size;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends

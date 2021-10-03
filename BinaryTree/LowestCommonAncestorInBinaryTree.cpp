#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    
    // Approach:
    /*
        1. As mentioned in the question , either both of the numbers exist or none of them do.
        2. Soo there is no such case where only one of the numbers is found in the entire tree.
        3. As soon as we find a number, we will return that node, now 2 cases arise.
        4. Either the second node is present below the first node which has been found, making the first node the lowest ancestor.
        5. Or the other node is present in some other subtree of the tree.
        6. Hence we return the answers from the left and the right subtree.
        7. For any node if both of the numbers are found, we will simply return that node as the LCA.
        8. Otherwise if only one of them is found, we will return the address of that found node only as it will be the LCA.
    */
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root == NULL){
            return NULL;
        }
        
        // Now we need to check whether the current node is x or y.
        if(root->data == n1 || root->data == n2){
            return root;
        }
        
        // Now we need to call recursion on both left and right and get the node from both the sides.
        
        Node* leftSubTree = lca(root->left , n1 , n2);
        Node* rightSubTree = lca(root->right, n1, n2);
        
        if(leftSubTree != NULL && rightSubTree != NULL){
            return root;
        }
        
        if(leftSubTree == NULL){
            return rightSubTree;
        }
        
        if(rightSubTree == NULL){
            return leftSubTree;
        }
    }
};

// { Driver Code Starts.

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}
  // } Driver Code Ends

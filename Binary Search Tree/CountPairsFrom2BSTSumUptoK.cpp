//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the right child for the current node
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

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void inorderTraversal(Node* root, unordered_map<int, int> &bstNodes){
        if(root == NULL){
            return;
        }
        
        inorderTraversal(root->left, bstNodes);
        bstNodes[root->data]++;
        inorderTraversal(root->right, bstNodes);
        
        return;
    }

    void countHelperFunction(Node* root, unordered_map<int, int> &bstNodes, int &count, int x){
        if(root == NULL){
            return;
        }
        
        countHelperFunction(root->left, bstNodes, count , x);
        
        int compliment = x - root->data;
        if(bstNodes.find(compliment) != bstNodes.end()){
            count++;
        }
        
        countHelperFunction(root->right, bstNodes, count , x);
        
        return;
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        if(root1 == NULL || root2 == NULL){
            return 0;
        }
        
        // We will create an unordered_map to store the elements of one of the BST'S.
        unordered_map<int, int> bstNodes;
        
        inorderTraversal(root1 , bstNodes);
        
        // After populating the map, we will check for the pairs in the other tree.
        int count = 0;
        countHelperFunction(root2 , bstNodes, count, x);
        
        return count;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}
  // } Driver Code Ends

#include<bits/stdc++.h>
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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    
    // Approach:
    /*
        1. As we need to find that if some nodes are swapped then the 2 trees should be same.
        2. We will start at the root node, now there are 2 conditions:
            2.1 That the nodes in the level below are already in same order.
            2.2 The nodes, if swapped will be the same.
        3. Hence we will check both the conditions and both are false, hence the tree cannot be isomorphic.
    */
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        
        if(root1 == NULL || root2 == NULL){
            return false;
        }
        
        
        // Now the next level nodes might be in same order in both the trees.
        // The other case is that the nodes need to be swapped and after swapping they will become same.
        
        if(root1->data != root2->data){
            return false;
        }
        
        bool caseOne = isIsomorphic(root1->left , root2->left) && 
                        isIsomorphic(root1->right , root2->right);
                        
        bool caseTwo = isIsomorphic(root1->left , root2->right) && 
                        isIsomorphic(root1->right , root2->left);
    
    
        return caseOne || caseTwo;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s1,s2;
		getline(cin,s1);
		getline(cin,s2);
		Node* root1 = buildTree(s1);
		Node* root2 = buildTree(s2);
		Solution obj;
		if(obj.isIsomorphic(root1,root2))
		    cout<<"Yes"<<endl;
		else
		    cout<<"No"<<endl;
    }
    return 0;
}
  // } Driver Code Ends

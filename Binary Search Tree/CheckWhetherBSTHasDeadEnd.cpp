#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

// The following solution has the complexity as:

// Time Complexity : O(N)
// Space Complexity : O(N)

void findLeafNodes(Node* root, unordered_map<int, int> &leafNodes){
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        leafNodes[root->data]++;
    }
    
    findLeafNodes(root->left, leafNodes);
    findLeafNodes(root->right, leafNodes);
    
    return;
}

void findAllNodes(Node* root, unordered_map<int, int> &allNodes){
    if(root == NULL){
        return;
    }
    
    findAllNodes(root->left , allNodes);
    allNodes[root->data]++;
    findAllNodes(root->right , allNodes);
    
    return;
}

bool isDeadEnd(Node *root)
{
    unordered_map<int, int> leafNodes;
    unordered_map<int, int> allNodes;
    
    // First we will populate the leaf node map.
    findLeafNodes(root , leafNodes);
    
    // Second fill the all nodes map.
    findAllNodes(root , allNodes);
    allNodes[0]++;
    // Lastly, we will check for all leaf nodes if their one greater and one smaller is present in the allNodes or not.
    
    for(auto x:leafNodes){
        int left = x.first - 1;
        int right = x.first + 1;
        
        if(allNodes.find(left) != allNodes.end() && allNodes.find(right) != allNodes.end()){
            return true;
        }
    }
    
    return false;
}

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

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

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/*
Structure of the binary Search Tree is as
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
// your task is to complete the Function
// Function should return median of the BST
void convertToDLL(Node* root, Node* &prev, Node* &head, int& count){
    if(root == NULL){
        return;
    }
    
    convertToDLL(root->left, prev, head, count);
    
    // This is where we reconnect our nodes.
    if(prev == NULL){
        prev = root;
        head = root;
    }else{
     	root->left = prev;
        prev->right = root;
        prev = root;
    }
    count++;
    
    convertToDLL(root->right , prev, head, count);
}

float findMedian(struct Node* root) 
{
    // first we can convert the tree into a doubly linked list by doing an inorder traversal.
    // Then perform the process of finding mid value as usual.
    
    // Taking the left node as prev. Right node as next;
    if(root == NULL){
        return -1;
    }
    Node* prev = NULL;
    Node* head = NULL;
    
    int count = 0;
    convertToDLL(root, prev, head, count);
    
    Node* slow = head;
    Node* fast = head->right;
    while(fast != NULL && fast->right!= NULL){
        slow = slow->right;
        fast = fast->right->right;
    }
    if(count % 2 == 0){
       	return (slow->data + slow->right->data) / 2.0;
    }
    
    return slow->data/1.0;
}



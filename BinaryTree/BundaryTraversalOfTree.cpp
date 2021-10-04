#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};



BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


// Code here

// Printing the left child is priority.
// If the node is null, we do nothing for now.
void printLeftBoundary(BinaryTreeNode<int>* root, vector<int>& ans){
    
    // Always check the base case.
    if(root == NULL){
        // Do nothing and return.
        return;
    }
    
    
    // We have to check whether the left child exists for the current Node or not.
    if(root->left != NULL){
        // We can push out current Node into the answer as it is a left boundary point.
        ans.push_back(root->data);
        // Call the printLeftBoundary recursively on the left child.
        printLeftBoundary(root->left,ans);
    }
    
    // Only if we dont have a left child, we will check for a right child.
    // This is because the right child, may be a boundary point in the left Subtree.
    else if(root->right != NULL){
        ans.push_back(root->data);
        printLeftBoundary(root->right,ans);
        
    }
    
    // If no condition is satisfied, it means we have hit a leaf node.
    
}


// Now we shall handle the leaf nodes occurence in a left to right fashion.
// As again the left node has to come first, we will call the function on the left child first always.
void printLeaf(BinaryTreeNode<int>* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    
    // Now we will look for a leaf node in the left side recursively.
    printLeaf(root->left,ans);
    
    // Now in the end of the above statement, we shall reach to a leaf node on the leftmost side.
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    
    // Now if all the left most nodes are dealt with, we shall go to right ones.
    // This is beacuse we have to print the leaf nodes in a left to right fahsion/anticlockwise.
    printLeaf(root->right,ans);
    return;
}


// Now we shall print the right boundary since we are done with all the left and leaf nodes.
void printRightBoundary(BinaryTreeNode<int>* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    
    // Now getting the right nodes is the priority, but in a reverse fashion.
    if(root->right != NULL){
        // We will get the last right node forst and then insert to get it in a reverse fashion.
        printRightBoundary(root->right,ans);
        ans.push_back(root->data);
    }
    // Only if we run out of the right boundary points, we should always check if the nodes are going to the left or not.
    else if(root->left != NULL){
        printRightBoundary(root->left,ans);
        ans.push_back(root->data);
    }
    
}

void solve(BinaryTreeNode<int>* root){
    	/* Don't write main().
	* Don't read input, it is passed as function argument.
	*/
	vector<int> ans;
    ans.push_back(root->data);
    // Now we will call the 3 functions required.
    printLeftBoundary(root->left,ans);
    printLeaf(root,ans);
    printRightBoundary(root->right,ans);
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    solve(root);
}

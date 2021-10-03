#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode{
	public:
		T data;
		TreeNode<T>* left;
		TreeNode<T>* right;
		
		TreeNode(T data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
		
		~TreeNode(){
			delete left;
			delete right;
		}
};

TreeNode<int>* createLevelWise(){
	int rootData;
	cout << "Enter the root data : ";
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int leftChild;
		cout << "Enter the left child of " << currNode->data << " : ";
		cin >> leftChild;
		
		if(leftChild != -1){
			TreeNode<int>* leftNode = new TreeNode<int>(leftChild);
			currNode->left = leftNode;
			pendingChild.push(leftNode);
		}
		
		int rightChild;
		cout << "Enter the right child of " << currNode->data << " : ";
		cin >> rightChild;
		
		if(rightChild != -1){
			TreeNode<int>* rightNode = new TreeNode<int>(rightChild);
			currNode->right = rightNode;
			pendingChild.push(rightNode);
		}
	}
	
	return root;
}

void printLevelWise(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	pendingChild.push(NULL);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		if(currNode == NULL){
			if(pendingChild.size() == 0){
				cout << endl;
				break;
			}else{
				pendingChild.push(NULL);
				cout << endl;
			}
		}else{
			cout << currNode->data << " ";
			if(currNode->left != NULL){
				pendingChild.push(currNode->left);
			}
			
			if(currNode->right != NULL){
				pendingChild.push(currNode->right);
			}	
		}
		
	}
	
	return;
}

// Code here .
// This is the preorder recursive code.
void preorder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	
	return;
}

// This is an iterative approach to preorder traversal.
/*
Approach:
	1. Since this is a preorder traversal , (root->left->right).
	2. We will use the help of a stack.
	3. We will put the right child before the left child because in stack then the order will be left first and then right.
	4. And we also do this because of the way preorder traversal works.
*/
void preorderIter(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	stack<TreeNode<int>*> pendingNodes;
	// first we will input the root node.
	pendingNodes.push(root);
	
	while(!pendingNodes.empty()){
		TreeNode<int>* currNode = pendingNodes.top();
		pendingNodes.pop();
		
		
		cout << currNode->data << " ";
		
		// Since this is a stack, we will input the right node first if it exists.
		if(currNode->right != NULL){
			pendingNodes.push(currNode->right);	
		}
		
		if(currNode->left != NULL){
			pendingNodes.push(currNode->left);
		}
	}
	
	
	return;
}


int main(){
	TreeNode<int>* root = createLevelWise();
	
	// Recusrive printing in preorder.
	preorder(root);
	
	cout << endl;
	
	preorderIter(root);
	
	
	return 0;
}

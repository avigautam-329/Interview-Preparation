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

// Doing the recursive way of inorder traversal.
void inorder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	// left->root->right
	inorder(root->left);
	
	cout << root->data << " ";
	
	inorder(root->right);
	
	return;
}

// Now onto the iterative way of doing inorder.
void inorderIter(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	stack<TreeNode<int>*> pendingNodes;
	//pendingNodes.push(root);
	
	// As we have to go to the left subtree first, soo we do not push the top directly into the stack.
	TreeNode<int>* currNode = root;
	
	while(!pendingNodes.empty() || currNode != NULL){
		// If the node exists, we push it into the stack ans move to the left.
		if(currNode != NULL){
			pendingNodes.push(currNode);
			
			currNode = currNode->left;
		}else{
			// We pop the last entered node and print it, then we move to the right.
			currNode = pendingNodes.top();
			pendingNodes.pop();
			
			cout << currNode->data << " ";
			
			currNode = currNode->right;
		}
		
		
	}
	return;
}

int main(){
	TreeNode<int>* root = createLevelWise();
	
	// Now we will call the recursive way of inorder first.
	inorder(root);
	
	cout << endl;
	
	inorderIter(root);
	
	return 0;
}

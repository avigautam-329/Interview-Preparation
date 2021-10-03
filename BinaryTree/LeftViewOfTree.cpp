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

void printLeftView(TreeNode<int>* root, int currLevel , int& maxLevel){
	if(root == NULL){
		return;
	}
	
	if(maxLevel < currLevel){
		cout << root->data << " ";
		maxLevel = currLevel;
	}
	
	// Next we call on the left subtree first and then on right.
	printLeftView(root->left , currLevel + 1, maxLevel);
	printLeftView(root->right , currLevel + 1, maxLevel);
}


int main(){
	TreeNode<int>* root = createLevelWise();
	
	// Now we have to print the left view of the tree.
	int maxLevel = 0;
	printLeftView(root , 1 , maxLevel);
		
	return 0;
}

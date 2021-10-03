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
		
		if(leftChild != -99){
			TreeNode<int>* leftNode = new TreeNode<int>(leftChild);
			currNode->left = leftNode;
			pendingChild.push(leftNode);
		}
		
		int rightChild;
		cout << "Enter the right child of " << currNode->data << " : ";
		cin >> rightChild;
		
		if(rightChild != -99){
			TreeNode<int>* rightNode = new TreeNode<int>(rightChild);
			currNode->right = rightNode;
			pendingChild.push(rightNode);
		}
	}
	
	return root;
}

// Code here.
void findKPathInTree(TreeNode<int>* root, int k, vector<int> currPath, vector<vector<int> >& res){
	if(root == NULL){
		return;
	}
	
	// let's exclude first as well so we can just have different starting nodes.
	if(currPath.size() == 0){
		findKPathInTree(root->left , k , currPath , res);

		findKPathInTree(root->right , k , currPath , res);
	}

	// Now for each element we have 2 options, whether to make it as a starting node in out path or not.
	// First we will explore if we include the node.
	currPath.push_back(root->data);
	if(k - root->data == 0){
		// This is a valid path and hence can be taken into the res now.
		res.push_back(currPath);
		return;
	}
	
	if(k - root->data < 0){
		return;
	}
	
	findKPathInTree(root->left , k - root->data, currPath , res);

	findKPathInTree(root->right , k - root->data, currPath , res);
	
	currPath.pop_back();

}


int main(){
	// We need to creata a tree first.
	TreeNode<int>* root = createLevelWise();
	
	int k;
	cout << "Enter the k sum to be evaluated: ";
	cin >> k;
	
	// Creating a vector matrix to store the answers into.
	vector<vector<int> > res;
	
	// Creating another vector to keep track of bracktracking.
	vector<int> currPath;
	
	// Now the function to populate the res matrix.
	findKPathInTree(root , k, currPath , res);
	
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

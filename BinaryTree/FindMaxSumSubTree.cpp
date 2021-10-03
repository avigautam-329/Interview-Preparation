#include<iostream>
#include<queue>
#include<vector>
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

// Code Here.
int findMaxSum(TreeNode<int>* root , int &maxSum){
	if(root == NULL){
		return 0;
	}
	
	int ls = findMaxSum(root->left , maxSum);
	int rs = findMaxSum(root->right , maxSum);
	
	int currSum = root->data + ls + rs;
	
	if(currSum > maxSum){
		maxSum = currSum;
	}
	
	return currSum;
}

int main(){
	
	TreeNode<int>* root = createLevelWise();
	
	int maxSum = 0;
	
	cout << "The maxSum from all subtree's is : " << findMaxSum(root , maxSum) << endl;
	
	return 0;
}

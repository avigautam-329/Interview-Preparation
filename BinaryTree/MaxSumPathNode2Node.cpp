#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode<T>* left;
		BinaryTreeNode<T>* right;
		
		BinaryTreeNode(T val){
			this->data = val;
			this->left = NULL;
			this->right = NULL;
		}
};

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "Enter the root data: ";
	cin >> rootData;
	
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		BinaryTreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int leftChildData;
		cout << "Enter the left child of " << currNode->data << " : ";
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChildData);
			pendingChild.push(leftNode);
			currNode->left = leftNode;
		}
		
		int rightChildData;
		cout << "Enter the right child of " << currNode->data << " : ";
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChildData);
			pendingChild.push(rightNode);
			currNode->right = rightNode;
		}
	}
	return root;
}


int maxSumNode2Node(BinaryTreeNode<int>* root, int &res){
	if(root == NULL){
		return 0;
	}
	
	// Now we need to write out hypothesis.
	int leftSum = maxSumNode2Node(root->left, res);
	int rightSum = maxSumNode2Node(root->right, res);
	
	// Now we will consider both the possiblities that the current node can take to create the maxSumPath.
	// First option is to find the maxSum from both sides by using max() and add the currNode->data to it.
	int temp = max(max(leftSum,rightSum) + root->data, root->data);
	
	// The second option is to take the possibilty that the current node can be a part of the maxSumPath node 2 node of its own subtree.
	// We will find which option is better for the current node.
	// The first one or the second option.
	int subAns = max(leftSum+rightSum+root->data, temp);
	res = max(res,subAns);
	
	// We are returning the subAns only because the decision of the node before this one depends on the max of the both choices.
	return subAns;
}

int main(){
	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	
	int res = INT_MIN;
	int maxSumPath = maxSumNode2Node(root,res);
	cout << "The maximum sum path is : " << max(maxSumPath, res);
	cout << endl;
	return 0;
}

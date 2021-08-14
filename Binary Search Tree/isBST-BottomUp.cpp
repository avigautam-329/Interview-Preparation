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
		
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
};

class isBSTReturn{
	public:
		int minimum;
		int maximum;
		bool isBSTtrue;
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

isBSTReturn isBST(BinaryTreeNode<int>* root){
	if(root == NULL){
		// We return the base output.
		isBSTReturn output;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		output.isBSTtrue = true;
		return output;	
	}
	
	// Now we need the output object from both the left and right children before we can check for the current root value.
	isBSTReturn leftOutput = isBST(root->left);
	isBSTReturn rightOutput = isBST(root->right);
	
	// Now we need to update the new minimum and maximum taking in account of the the current Node's data.
	int maximum = max(root->data, max(leftOutput.maximum , rightOutput.maximum));
	int minimum = min(root->data , min(leftOutput.minimum , rightOutput.minimum));
	
	// We need to check the 4 conditions to see if the current subtree is a BST or not.
	bool isBSTfinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBSTtrue && rightOutput.isBSTtrue;
	
	isBSTReturn output;
	output.maximum = maximum;
	output.minimum = minimum;
	output.isBSTtrue = isBSTfinal;
	return output;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	
	isBSTReturn finalOutput = isBST(root);
	
	if(finalOutput.isBSTtrue){
		cout << "This BT is BST." << endl;
	}else{
		cout <<"This BT is not BST." << endl;
	}
	return 0;
}

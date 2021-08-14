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

// The time complexity for this algorithm is T.C = O(n * height of tree).
// This is a bad tme complexity.

int maximum(BinaryTreeNode<int>* root){
	if(root == NULL){
		return INT_MIN;
	}
	
	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
	if(root == NULL){
		return INT_MAX;
	}
	
	return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){
	if(root == NULL){
		return true;
	}
	
	// We need the left maximum and the right minimum.
	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);
	
	// Now we need to see if the  current node satifies all the 4 conditions or not.
	bool ans = (root->data > leftMax) && root->data <= rightMin && isBST(root->left) && isBST(root->right);
	return ans;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	
	if(isBST(root)){
		cout << "This BT is BST." << endl;
	}else{
		cout <<"This BT is not BST." << endl;
	}
	return 0;
}

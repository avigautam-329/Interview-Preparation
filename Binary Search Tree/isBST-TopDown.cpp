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

bool isBST(BinaryTreeNode<int>* root, int minimum = INT_MIN, int maximum = INT_MAX){
	if(root == NULL){
		return true;
	}
	
	// Now the first thing we need to check is whether the current node data lies in the constraint or not.
	if(root->data > maximum || root->data < minimum){
		return false;
	}
	
	// Now we need to pass the new constraints over to the left and right subtree.
	bool isLeftTrue = isBST(root->left, minimum , root->data - 1);
	bool isRightTrue = isBST(root->right, root->data, maximum);
	
	return isLeftTrue && isRightTrue;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	
	//isBSTReturn finalOutput = isBST(root);
	
	if(isBST(root)){
		cout << "This BT is BST." << endl;
	}else{
		cout <<"This BT is not BST." << endl;
	}
	return 0;
}

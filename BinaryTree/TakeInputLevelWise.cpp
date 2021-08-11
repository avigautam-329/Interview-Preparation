#include<iostream>
#include<queue>
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
	cout << "Enter the root value: ";
	cin >> rootData;
	if(rootData == -1){
		return NULL;
	}
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	
	// Now we need a queue to take input level wise.
	queue<BinaryTreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		// Now we need to get the front of the queue to take the input for its children.
		BinaryTreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		// Take input for the left node of the parent node.
		int leftChildData;
		cout << "Enter the left child of "<< currNode->data << ": ";  
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode<int>* leftChildNode = new BinaryTreeNode<int>(leftChildData);
			pendingChild.push(leftChildNode);
			currNode->left = leftChildNode;
		}
		
		// Now take input for the right child of the current node.
		int rightChildData;
		cout << "Enter the right child of " << currNode->data << ": ";
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode<int>* rightChildNode = new BinaryTreeNode<int>(rightChildData);
			pendingChild.push(rightChildNode);
			currNode->right = rightChildNode;
		}
	}
	return root;
	
}

void printTree(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	cout << root->data << " :";
	if(root->left != NULL){
		cout << "L" << root->left->data << ",";
	}
	
	if(root->right != NULL){
		cout << "R" << root->right->data << ",";
	}
	
	cout << endl;
	
	printTree(root->left);
	printTree(root->right);
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	
	return 0;
}

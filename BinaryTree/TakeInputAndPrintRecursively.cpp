#include<iostream>
using namespace std;

template <typename T>
class binaryTreeNode{
	public:
		T data;
		binaryTreeNode<T>* left;
		binaryTreeNode<T>* right;
		
		binaryTreeNode(T val){
			this->data = val;
			this->left = NULL;
			this->right = NULL;
		}
		
		~binaryTreeNode(){
			delete left;
			delete right;
		}
};

// This is the most complicated way to take input, because you need to know recursion well.
binaryTreeNode<int>* takeInput(){
	int rootData;
	cout << "Enter the data: ";
	cin >> rootData;
	
	if(rootData == -1){
		return NULL;
	}
	
	binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
	
	binaryTreeNode<int>* leftChild = takeInput();
	binaryTreeNode<int>* rightChild = takeInput();
	
	root->left = leftChild;
	root->right = rightChild;
}

void printTree(binaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	cout << root->data << ": ";
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
	
	binaryTreeNode<int>* root = takeInput();
	printTree(root);
	
	return 0;
}

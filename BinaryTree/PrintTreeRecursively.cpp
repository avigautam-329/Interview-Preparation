#include<iostream>
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
			// Important.
			// Even if left and right have NULL in them, the delete function will not show an error and will just ignore them.
			
			delete left;
			delete right;
		}
};

void printTree(BinaryTreeNode<int>* root){
	
	// This is the base case.
	if(root == NULL){
		return;
	}
	
	cout << root->data << " : ";
	if(root->left != NULL){
		cout << "L" << root->left->data << ",";
	}
	if(root->right != NULL){
		cout << "R" << root->right->data << ",";
	}
	cout << endl;
	
	// Now we will call the print Tree function on both left and right subtree.
	printTree(root->left);
	printTree(root->right);
}

int main(){
	
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
	
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(20);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(30);
	
	root->left = node1;
	root->right = node2;
	
	
	printTree(root);
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;


template <typename T>
class TreeNode{
	
	public:
		T data;
	
		// For a generic tree, we need to maintain a vector containing address of next node.
	 	vector<TreeNode<T>*> children;
	 	
	 	TreeNode(int val){
	 		this->data = val;
		}
		
		~TreeNode(){
			for(int i = 0; i < children.size(); i++){
				delete children[i];
			}
		}
};


// Function to take the input recusively.
TreeNode<int>* takeInput(){
	int rootData;
	cout << "Enter the data: ";
	cin >> rootData;
	
	//First : We will create the node for the current root.
	TreeNode<T>* root = new TreeNode<T>(rootData);
	
	int numChild;
	cout << "Enter the number of children that " << rootData << " will have : ";
	cin >> numChild;
	
	//Now we will use a for loop to populate the children nodes.
	for(int i = 0; i < numChild; i++){
		// We need to create a TreeNode pointer in order to store the address of the child node to store its address.
		TreeNode<T>* child = takeInput();
		
		// Once we have the subTree with the current child as its root node. We will push its address in the children vector of its rootNode or parent node.
		root->children.push_back(child);
	}
	
	return root;
}


void printTree(TreeNode<T>* root){
	// We don't have a base case for this function.
	// But we have an edge case instead.
	if(root == NULL){
		return;
	}
	
	cout << root->data << ":";
	
	// First we will print all the children of the current node.
	// I have created an if else statement because I don't want to print a comma after the last child.
	for(int i = 0; i < root->children.size(); i++){
		if(i == root->children.size()-1){
			cout << root->children[i]->data;
		}else{
			cout << root->children[i]->data << ",";
		}
	}
	cout << endl;
	// Now we need to create another for loop, too call the print function on all of the children of the root node.
	for(int j = 0; j < root->children.size(); j++){
		printTree(root->children[j]);
	}
}


// We have 2 ways to delete the tree.

//1. Recusively delete the node using post Order traversal.
void deleteTree(TreeNode<int>* root){
	for(int i = 0; i < root->children.size(); i++){
		deleteTree(root->children[i]);
	}
	delete root;
}

// 2. Override the delete function of the class;

int main(){
	// Manually make a tree.
	
	/*
	TreeNode<int>* root = new TreeNode<int>(10);
	
	// Lets create the children nodes of this tree.
	TreeNode<int>* child1 = new TreeNode<int>(20);
	TreeNode<int>* child2 = new TreeNode<int>(30);
	TreeNode<int>* child3 = new TreeNode<int>(40);
	
	root->children.push_back(child1);
	root->children.push_back(child2);
	root->children.push_back(child3);
	*/
	
	
	
	// Now let's try taking the input of the tree from the user recursively.
	TreeNode<int>* root = takeInput();
	
	// Now lets print the tree in a way that gives intuition about its structure.
	printTree(root);
	return 0;
}

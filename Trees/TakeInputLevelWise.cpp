#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
	public:
		T data;
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


// Lets create the function to take the input fot the tree level wise.
TreeNode<int>* takeInputLevelWise(){
	
	// First lets create the root node.
	int rootData;
	cout << "Enter root Node: ";
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	// Second let's create a queue to store the pending nodes.
	queue<TreeNode<int>*> pendingChild;
	
	// Push the root node into the queue.
	pendingChild.push(root);
	while(!pendingChild.empty()){
		// Now we need to pop the pending child.
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		// Ask for the number of children it will have.
		int n;
		cout << "Number of children for node " << currNode->data << " : ";
		cin >> n;
		
		// Now we need to take the children nodes, put them in the queue and also link them to its parent node.
		for(int i = 0; i < n; i++){
			int childData;
			cout << "Enter the " << i + 1 <<"th node of " << currNode->data << " : ";
			cin >>childData;
			
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			pendingChild.push(childNode);
			currNode->children.push_back(childNode);
		}
	}
	
	return root;
}


void printTree(TreeNode<int>* root){
	
	// This is an edge case.
	if(root == NULL){
		return;
	}
	
	cout << root->data << ":";
	//Now we will print the children of the current node.
	for(int i = 0; i < root->children.size();i++){
		if(i == root->children.size() - 1){
			cout << root->children[i]->data;
		}else{
			cout << root->children[i]->data <<",";
		}
	}
	cout << endl;
	
	// Now to print the other nodes we will make a for loop to call the print function one by one on the children node.
	for(int i = 0; i < root->children.size(); i++){
		printTree(root->children[i]);
	}
}

int main(){
	// In this program we will take the input of the tree level wise.
	
	TreeNode<int>* root = takeInputLevelWise();
	
	//print the tree that we have created.
	printTree(root);
	
	return 0;
}

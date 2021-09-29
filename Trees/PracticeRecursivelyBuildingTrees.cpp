#include<iostream>
#include<vector>
using namespace std;



// This is the treeNode class for N-ary Tree.
template <typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data){
			this->data = data;
		}
		
		~TreeNode(){
			// We will always delete the children first.
			for(int i = 0; i < children.size(); i++){
				delete this->children[i];
			}
		}
};

TreeNode<int>* createTree(){
	int data;
	cout << "Enter the root data : ";
	cin >> data;
	
	// Create a treeNode. 
	TreeNode<int>* root = new TreeNode<int>(data);
	
	//Next we need to take input for it's number of chidlren and call 
	int childNum;
	cout << "Enter the number of children: ";
	cin >> childNum;
	for(int i = 0; i < childNum; i++){
		TreeNode<int>* child = createTree();
		
		root->children.push_back(child);
	}
	
	return root;
}

void printTree(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	cout << root->data << " : " ;
	
	// First we will print all the children of the current node.
	for(int i = 0; i < root->children.size(); i++){
		cout << root->children[i]->data << " , ";
	}
	cout << endl;
	// Now we will call printTree on each child node.
	for(int i = 0; i < root->children.size(); i++){
		printTree(root->children[i]);
	}
	
	return;
}

int main(){
	TreeNode<int>* root = createTree();
	
	printTree(root);
	
	return 0;
}

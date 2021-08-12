#include<iostream>
#include<utility>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode<int>* left;
		BinaryTreeNode<int>* right;
		
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
	
	if(rootData == -1){
		return NULL;
	}
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingChild;
	
	pendingChild.push(root);
	while(!pendingChild.empty()){
		BinaryTreeNode<int> *currNode = pendingChild.front();
		pendingChild.pop();
		
		
		// Taking the input for the left node.
		int leftChildData;
		cout << "Enter the left child of " << currNode->data << " :";
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode<int>* leftChildNode = new BinaryTreeNode<int>(leftChildData);
			pendingChild.push(leftChildNode);
			currNode->left = leftChildNode;
		}
		
		// Take input for right child of the node.
		int rightChildData;
		cout << "Enter the right child of " << currNode->data <<": ";
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode<int>* rightChildNode = new BinaryTreeNode<int>(rightChildData);
			pendingChild.push(rightChildNode);
			currNode->right = rightChildNode;
		}
	}
	return root;
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<int , int> p(0,0);
		return p;
	}
	
	pair<int , int> leftSubtree = heightDiameter(root->left);
	pair<int , int> rightSubtree = heightDiameter(root->right);
	
	// Just to clarify the code better.
	int lh = leftSubtree.first;
	int ld = leftSubtree.second;
	int rh = rightSubtree.first;
	int rd = rightSubtree.second;
	
	// This contains the height of the current node.
	int height = 1 + max(lh , rh);
	int diameter = max(lh + rh,max(ld,rd));
	pair<int, int> p(height,diameter);
	return p;
	
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	
	// This is the pair where we will receive the max height and also the max diameter of a tree.
	pair<int,int> p = heightDiameter(root);
	cout << "The height of the tree is: " << p.first << endl;
	cout << "The diameter of the tree is: " << p.second << endl;
	return 0;
}

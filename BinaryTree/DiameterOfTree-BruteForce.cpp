#include<iostream>
#include<queue>
using namespace std;

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

int height(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}


// Time Complexity for worst case is O(n * height of tree).
int findDiameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	
	// Now lets find the value for all the three options;
	int option1 = height(root->left) + height(root->right);
	int option2 = findDiameter(root->left);
	int option3 = findDiameter(root->right);
	return max(option1,max(option2,option3));
}

int main(){
	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	
	cout << "The diameter of the tree is: " << findDiameter(root) << endl;
	
	return 0;
}

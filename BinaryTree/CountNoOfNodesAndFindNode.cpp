#include<iostream>
#include<queue>
using namespace std;


template <typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode<T>* left;
		BinaryTreeNode<T>* right;
		
		BinaryTreeNode(int val){
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

void printTreeLevelWise(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	queue<BinaryTreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		BinaryTreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		cout << currNode->data << ": ";
		if(currNode->left != NULL){
			cout << "L:" << currNode->left->data << ",";
			pendingChild.push(currNode->left);
		}else{
			cout << "L:" << -1 < ",";
		}
		
		if(currNode->right != NULL){
			cout << "R:" << currNode->right->data;
			pendingChild.push(currNode->right);
		}else{
			cout << "R:" << -1;
		}
		cout << endl;
	}
}


// THIS IS THE FUNCTION TO COUNT THE NUMBER OF NODES.
int countNoOfNodes(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	return countNoOfNodes(root->left) + countNoOfNodes(root->right) + 1;
	
}

// FUCNTION TO FIND A PARTICULAR NODE IN THE BINARY TREE.
bool isNodePresent(BinaryTreeNode<int>* root, int val){
	if(root == NULL){
		return false;
	}
	if(root->data = val){
		return true;
	}
	bool ans = isNodePresent(root->left, val) || isNodePresent(root->right, val);
	return ans;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTreeLevelWise(root);
	cout << "The number of nodes in the tree are: " << countNoOfNodes(root);
	cout << endl;
	int x;
	cout << "Enter the node to be searched : ";
	cin >> x;
	
	if(isNodePresent){
		cout << "The node is present in the tree." << endl;
	}else{
		cout << "The node is not present in the tree." << endl;
	}
	return 0;
}

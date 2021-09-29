#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
	public:
		T data;
		TreeNode<T>* left;
		TreeNode<T>* right;
		
		TreeNode(T data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
		
		~TreeNode(){
			delete left;
			delete right;
			
			// As it ends, deletes the node itself
		}
};

TreeNode<int>* createLevelWise(){
	int rootData;
	cout << "Enter the root data : ";
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int leftChild;
		cout << "Enter the left child of " << currNode->data << " : ";
		cin >> leftChild;
		
		if(leftChild != -1){
			TreeNode<int>* leftNode = new TreeNode<int>(leftChild);
			currNode->left = leftNode;
			pendingChild.push(leftNode);
		}
		
		int rightChild;
		cout << "Enter the right child of " << currNode->data << " : ";
		cin >> rightChild;
		
		if(rightChild != -1){
			TreeNode<int>* rightNode = new TreeNode<int>(rightChild);
			currNode->right = rightNode;
			pendingChild.push(rightNode);
		}
	}
	
	return root;
}

void printLevelWise(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	pendingChild.push(NULL);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		if(currNode == NULL){
			if(pendingChild.size() == 0){
				cout << endl;
				break;
			}else{
				pendingChild.push(NULL);
				cout << endl;
			}
		}else{
			cout << currNode->data << " ";
			if(currNode->left != NULL){
				pendingChild.push(currNode->left);
			}
			
			if(currNode->right != NULL){
				pendingChild.push(currNode->right);
			}	
		}
		
	}
	
	return;
}

//Code here.

// This operation can also be done using level order traversal.

// But this approach is using recursion.
void mirrorInPlace(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	swap(root->left , root->right);
	mirrorInPlace(root->left);
	mirrorInPlace(root->right);
	return;
}

int main(){
	TreeNode<int>* root = createLevelWise();
	
	cout << "Before mirroring : " << endl;
	printLevelWise(root);
	
	mirrorInPlace(root);
	
	cout << "After mirroring : " << endl;
	printLevelWise(root);
	
	
	
	return 0;
}

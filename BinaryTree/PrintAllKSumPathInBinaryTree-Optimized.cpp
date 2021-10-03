#include<bits/stdc++.h>
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
		
		if(leftChild != -99){
			TreeNode<int>* leftNode = new TreeNode<int>(leftChild);
			currNode->left = leftNode;
			pendingChild.push(leftNode);
		}
		
		int rightChild;
		cout << "Enter the right child of " << currNode->data << " : ";
		cin >> rightChild;
		
		if(rightChild != -99){
			TreeNode<int>* rightNode = new TreeNode<int>(rightChild);
			currNode->right = rightNode;
			pendingChild.push(rightNode);
		}
	}
	
	return root;
}

// Code here.
void printAllKPath(TreeNode<int>* root , int k , vector<int> currPath){
	if(root == NULL){
		return;
	}
	
	// We include the current node data into the vector and proceed to go left and right till we further cannot.
	currPath.push_back(root->data);
	
	printAllKPath(root->left , k , currPath);
	
	printAllKPath(root->right, k , currPath);
	
	// Once we cannot go any further now we start from the last element inserted into the vector and keep going back in the vector
	// and maintain a sum, if sum == k at any point we print that path.
	int sum = 0;
	for(int i = currPath.size() - 1; i >= 0; i--){
		sum += currPath.at(i);
		
		if(sum == k){
			// We have found a path and now we should print it.
			for(int j = i; j < currPath.size(); j++){
				cout << currPath[j] << " ";
			}
			
			cout << endl;
		}
	}
	
	// Now we pop back the last inserted element.
	currPath.pop_back();
	
	return;
}



int main(){
	
	// We need to creata a tree first.
	TreeNode<int>* root = createLevelWise();
	
	int k;
	cout << "Enter the k sum to be evaluated: ";
	cin >> k;
	
	vector<int> currPath;
	
	printAllKPath(root , k , currPath);
		
	return 0;
}

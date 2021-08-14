#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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
};

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "Enter the root Data: ";
	cin >> rootData;
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	
	queue<BinaryTreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		BinaryTreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int leftData;
		cout << "Enter the left child of the node " << currNode->data << " : ";
		cin >> leftData;
		if(leftData != -1){
			BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftData);
			pendingChild.push(leftNode);
			currNode->left = leftNode;
		}
		
		int rightData;
		cout << "Enter the right child of the node " << currNode->data << " : ";
		cin >> rightData;
		if(rightData != -1){
			BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightData);
			pendingChild.push(rightNode);
			currNode->right = rightNode;
		}
	}
	
	return root;
}

// Now lets write the function to find the path to a node in reverse order.
vector<int>* findPath2Node(BinaryTreeNode<int>* root, int target){
	if(root == NULL){
		return NULL;
	}
	
	// if the curent node is the target we want to find.
	if(root->data == target){
		vector<int>* ans = new vector<int>;
		ans->push_back(root->data);
		return ans;
	}
	
	// If the current root is not the target, then we get the vectors from left and right and if one of them is not NULL, then we add the current Node to the path.
	vector<int>* leftOutput = findPath2Node(root->left, target);
	if(leftOutput != NULL){
		leftOutput->push_back(root->data);
		return leftOutput;
	}
	
	vector<int>* rightOutput = findPath2Node(root->right, target);
	if(rightOutput != NULL){
		rightOutput->push_back(root->data);
		return rightOutput;
	}
	
	return NULL;
}


int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	
	int target;
	cout << "Enter the value to be searched: ";
	cin >> target;
	
	vector<int> *res = findPath2Node(root , target);
	if(res != NULL){
		for(int i = 0; i < res->size(); i++){
			cout << res->at(i) << " ";
		}
		cout << endl;
	}else{
		cout << "The node was not found in this binary Tree." << endl;
	}
	
	return 0;
}


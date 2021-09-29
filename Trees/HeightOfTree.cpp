#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data){
			this->data = data;
		}
};

TreeNode<int>* createTreeLevelWise(){
	int rootData;
	cout << "Enter the root Node's data: ";
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	// Now to take input level wise/ level Wise Traversal, we need to maintain a queue.
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int childNum;
		cout << "Enter the number of children of " << currNode->data << " :";
		cin >> childNum;
		
		for(int i = 0; i < childNum; i++){
			int childData;
			cout << "Enter the Child node data of " << currNode->data << " : ";
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			currNode->children.push_back(childNode);
			pendingChild.push(childNode);
		}
	}
	return root;
}

void printTreeLevelWise(TreeNode<int>* root){
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		cout << currNode->data << " : ";
		
		for(int i = 0; i < currNode->children.size(); i++){
			cout << currNode->children[i]->data << " , ";
			pendingChild.push(currNode->children[i]);
		}
		cout << endl;
	}
}

int heightOfTree(TreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	
	int currHeight = 0;
	for(int i = 0; i < root->children.size(); i++){
		currHeight = max(currHeight , heightOfTree(root->children[i]));
	}
	
	return currHeight + 1;
}

int main(){
	TreeNode<int>* root = createTreeLevelWise();
	
	int height = heightOfTree(root);
	
	cout << height << endl;
	
	return 0;
}

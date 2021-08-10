#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
	public:
		int data;
		vector<TreeNode<int>*> children;
		
		TreeNode(int val){
			this->data = val;
		}
};


TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << " Enter the root data :" ;
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int numChild;
		cout << "Enter the number of nodes for " << currNode->data << ":";
		cin >> numChild;
		
		for(int i = 0; i < numChild; i++){
			int childData;
			cout << "Enter the " << i + 1 <<"th child of the node " << currNode->data << " :";
			cin >> childData;
			
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			pendingChild.push(childNode);
			currNode->children.push_back(childNode);
		}
	}
	
	return root;
}


void printNodesAtDepthK(TreeNode<int>* root, int k){
	if(root == NULL){
		return;
	}
	
	if(k == 0){
		cout << root->data << " ";
		return;
	}
	
	for(int i = 0; i < root->children.size(); i++){
		printNodesAtDepthK(root->children[i], k-1);
	}
}

int main(){
	TreeNode<int>* root = takeInputLevelWise();
	
	int k;
	cout << "Enter the desired depth: ";
	cin >> k;
	
	printNodesAtDepthK(root,k);
	
	return 0;
}


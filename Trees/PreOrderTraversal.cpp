#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T val){
			this->data = val;
		}
		
		~TreeNode(){
			for(int i = 0; i < children.size(); i++){
				delete children[i];
			}
		}
};

TreeNode<int>* takeInputLevelWise(){
	int rootData;
	//cout << "Enter the root :";
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int numChild;
		//cout << "Enter the number of nodes of " << currNode->data << ": ";
		cin >> numChild;
		
		for(int i = 0; i < numChild; i++){
			int childData;
			//cout << "Enter the " << i + 1 << "th node of "<<currNode->data << " :";
			cin >> childData;
			
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			pendingChild.push(childNode);
			currNode->children.push_back(childNode);
		}
	}
	
	return root;
}

void preOrderTraversal(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	cout << root->data << " ";
	for(int i = 0; i < root->children.size(); i++){
		preOrderTraversal(root->children[i]);
	}
}

int main(){
	
	TreeNode<int>* root = takeInputLevelWise();
	
	preOrderTraversal(root);
	
	return 0;
}

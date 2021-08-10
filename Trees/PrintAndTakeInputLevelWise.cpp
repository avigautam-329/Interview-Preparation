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
};

// Function to take input level wise.
TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << " Enter root data : ";
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int numChild;
		cout << "Enter the number of children nodes for" << currNode->data << " : ";
		cin >> numChild;
		
		for(int i = 0; i < numChild; i++){
			int childData;
			cout << "Input the data for the " << i + 1 <<"th child of " << currNode->data << ": ";
			cin >> childData;
			
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			pendingChild.push(childNode);
			currNode->children.push_back(childNode);
		}
	}
	
	return root;
}

void printTreeLevelWise(TreeNode<int>* root){
	queue<TreeNode<int>*> pendingChild;
	
	pendingChild.push(root);
	while(!pendingChild.empty()){
		TreeNode<int> *currNode = pendingChild.front();
		pendingChild.pop();
		
		cout << currNode->data << ":";
		for(int i = 0; i < currNode->children.size(); i++){
			TreeNode<int>* child = currNode->children[i];
			cout << child->data << ",";
			
			pendingChild.push(child);
		}
		cout << endl;
	}
}

int main(){
	
	TreeNode<int>* root = takeInputLevelWise();
	printTreeLevelWise(root);
	return 0;
}

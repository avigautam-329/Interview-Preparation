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
	cout << "Enter the root :";
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int numChild;
		cout << "Enter the number of nodes of " << currNode->data << ": ";
		cin >> numChild;
		
		for(int i = 0; i < numChild; i++){
			int childData;
			cout << "Enter the " << i + 1 << "th node of "<<currNode->data << " :";
			cin >> childData;
			
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			pendingChild.push(childNode);
			currNode->children.push_back(childNode);
		}
	}
	
	return root;
}


// For this function, I have returned one only when the node has no children.
// For each root node, accumulate all of the leaf nodes it might return and simply return the answer.
int countLeafNode(TreeNode<int>* root){
	if(root == NULL)
		return -1;
	
	if(root->children.size() == 0){
		return 1;
	}
	
	int count = 0;
	for(int i = 0; i < root->children.size(); i++){
		count += countLeafNode(root->children[i]);
	}
	
	return count;
}

int main(){
	
	TreeNode<int>* root = takeInputLevelWise();
	
	int countLeaf = countLeafNode(root);
	cout << "Enter the number of leaf nodes: " << countLeaf << endl;
	return 0;
}

#include<iostream>
#include<queue>
#include<vector>
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

TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "Enter the root Node: ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingChild;
	pendingChild.push(root);
	
	while(!pendingChild.empty()){
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		int numChild;
		cout << "Enter the number of children nodes for " << currNode->data << " :";
		cin >> numChild;
		
		for(int i = 0 ; i < numChild; i++){
			
			int childData;
			cout << "Enter the " << i + 1 << "th node of " << currNode->data << " :";
			cin >> childData;
			TreeNode<int> *childNode = new TreeNode<int>(childData);
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
		TreeNode<int>* currNode = pendingChild.front();
		pendingChild.pop();
		
		cout << currNode->data << " :";
		
		for(int i = 0; i < currNode->children.size(); i++){
			cout << currNode->children[i]->data << ",";
			
			pendingChild.push(currNode->children[i]);
		}
		cout << endl;
	}
}


int noOfNodes(TreeNode<int>* root){
	if(root == NULL){
		return -1;
	}
	
	if(root->children.size() == 0){
		return 1;
	}
	
	int count = 0;
	for(int i = 0; i < root->children.size(); i++){
		count += noOfNodes(root->children[i]);
	}
	
	return 1 + count;
}

// This is the function to find the sum;
int sumOfNodes(TreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    
    if(root->children.size() == 0){
        return root->data;
    }
    
    int subTreeSum = 0;
    for(int i = 0; i < root->children.size(); i++){
        subTreeSum += sumOfNodes(root->children[i]);
    }
    
    return subTreeSum + root->data;
}

int main(){
	TreeNode<int>* root = takeInputLevelWise();

	printTreeLevelWise(root);
	
	int count = noOfNodes(root);
	cout << "The number of nodes in the given tree are: " << count << endl;
	
	int sum = sumOfNodes(root);
	cout << "The sum of the nodes is: " << sum <<endl;	
	return 0;
}

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
// Approach

/*
	1. If we encounter a negative sign or a number, that means a newNode has started and first we need to get that integer value.
	2. For that I am using a function got getNumber.
	3. We will check for the pointer start exceeding the size of the string after all major operations.
	4. For creating the tree we are using recursion here.
	5. When we encounter a '(' bracket, that means a new subtree node has started, soo we will first try to make the left subtree
		and then the right subtree.
	6. After getting the num value, we create it's corrosponding root node, we call it root , because it might be root node for a further subtree.
	7. Soo essentially the returning value of the recursive function is a root node of a further subtree.
	8. First we try to create the left subtree, when we encounter the ')' bracket we will return that node.
	9. Then if we encounter another '(', that means it is a start of a right subtree of the current parent node whose left subtree is already completed.
			  
*/


class TreeNode{
	public:
		int data;
		TreeNode* left;
		TreeNode* right;
		
		TreeNode(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

// Code here.
// We will use the string to create the tree.

int getNumber(string treeNodes, int &start){
	bool isNegative = false;
	if(treeNodes[start] == '-'){
		isNegative = true;
		start++;
	}
	
	int num = 0;
	while(start < treeNodes.size() && treeNodes[start] != '(' && treeNodes[start] != ')' ){
		num = (num * 10) + (int)(treeNodes[start] - '0');
		start++;
	}
	if(isNegative){
		return -1 * num;
	}
	
	return num;
}

TreeNode* createTree(string treeNodes, int &start){
	if(start >= treeNodes.size()){
		return NULL;
	}
	// Creating the current node to me made.
	
	int num = 0;
	
	if(treeNodes[start] == '-' || (treeNodes[start] >= '0' && treeNodes[start] <= '9')){
		// Call the fundtion to return a number.
		num = getNumber(treeNodes, start);
	}
	TreeNode* root = new TreeNode(num);
	
	// If the end of the string has been reached or not.
	if(start >= treeNodes.size()){
		return root;
	}
	
	if(start < treeNodes.size() && treeNodes[start] == '('){
		start++;
		root->left = createTree(treeNodes , start);
	}
	if(start < treeNodes.size() && treeNodes[start] == ')'){
		start++;
		return root;	
	}
	if(start < treeNodes.size() && treeNodes[start] == '('){
		start++;
		root->right = createTree(treeNodes , start);
	}
	
	if(start < treeNodes.size() && treeNodes[start] == ')'){
		start++;	
	}
	return root;
}

void printLevelWise(TreeNode* root){
	if(root == NULL){
		return;
	}
	
	queue<TreeNode*> pendingChild;
	pendingChild.push(root);
	pendingChild.push(NULL);
	
	while(!pendingChild.empty()){
		TreeNode* currNode = pendingChild.front();
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

int main(){
	string treeNodes;
	getline(cin , treeNodes);

	int start = 0;
	TreeNode* root = createTree(treeNodes, start);
	
	printLevelWise(root);
	
	return 0;
}

#include<iostream>
#include<utility>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode<int>* left;
		BinaryTreeNode<int>* right;
		
		BinaryTreeNode(T val){
			this->data = val;
			this->left = NULL;
			this->right = NULL;
		}
		
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
};


BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "Enter the root data: ";
	cin >> rootData;
	
	if(rootData == -1){
		return NULL;
	}
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingChild;
	
	pendingChild.push(root);
	while(!pendingChild.empty()){
		BinaryTreeNode<int> *currNode = pendingChild.front();
		pendingChild.pop();
		
		
		// Taking the input for the left node.
		int leftChildData;
		cout << "Enter the left child of " << currNode->data << " :";
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode<int>* leftChildNode = new BinaryTreeNode<int>(leftChildData);
			pendingChild.push(leftChildNode);
			currNode->left = leftChildNode;
		}
		
		// Take input for right child of the node.
		int rightChildData;
		cout << "Enter the right child of " << currNode->data <<": ";
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode<int>* rightChildNode = new BinaryTreeNode<int>(rightChildData);
			pendingChild.push(rightChildNode);
			currNode->right = rightChildNode;
		}
	}
	return root;
}


// Here we are handling the max and min at the same time and returning them in a pair.
// p.first -> minimum.
// p.second -> maximum.
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	if(root == NULL){
        pair<int,int> p(INT_MAX,INT_MIN);
        return p;
    }
    
    pair<int , int> leftSubtree = getMinAndMax(root->left);
    pair<int , int> rightSubtree = getMinAndMax(root->right);
    
    int leftMin = leftSubtree.first;
    int leftMax = leftSubtree.second;
    int rightMin = rightSubtree.first;
    int rightMax = rightSubtree.second;
    
    int maxCurr = max(root->data, max(leftMax,rightMax));
    int minCurr = min(root->data,min(leftMin,rightMin));
    
    pair<int, int> p(minCurr, maxCurr);
    return p;
}

int main(){
	
	BinaryTreeNode<int>* root = takeInputLevelWise();
	
	pair<int,int> p = getMinAndMax(root);
	cout << "The max element is : " << p.second << endl;
	cout << "The minimum element is : " << p.first << endl;
	return 0;
}

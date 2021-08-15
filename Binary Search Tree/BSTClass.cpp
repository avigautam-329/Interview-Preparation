#include<iostream>
#include<climits>
#include<queue>
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

class BST{
	// We need to make our root pointer to create a tree in this object.
	BinaryTreeNode<int>* root;
	
	public:
		// We need to create the constructor.
		// Just for fun , I am creating a default parameterized construtor as well.
		BST(){
			this->root = NULL;
		}
		
		BST(int val){
			this->root = new BinaryTreeNode<int>(val);
		}
		
		// Now we have to create the rest of the 3 functions.
		
	private:
		BinaryTreeNode<int>* insertNode(BinaryTreeNode<int>* currNode , int val){
			if(currNode== NULL){
				BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(val);
				return newNode;
			}
			
			// Now as we did in search operation, we have to find the optimal value for out newNode in the already exisiting tree.
			if(val <= currNode->data){
				currNode->left = insert(currNode->left, val);
			}else{
				currNode->right = insert(currNode->right , val);
			}
			return currNode;
		}
		
	public:
		
		void insertNode(int val){
			this->root = insertNode(root , val);
		}
		
	private:
		BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* currNode, int val){
			
			//Base case for if the given tree is empty.
			if(currNode == NULL){
				return NULL;
			}
			
			// If the element is less than the current Node value. OR greater than the current Node value.
			if(val < currNode->data){
				currNode->left = deleteNode(currNode->left, data);
				return currNode;
			}else if(val > currNode->data){
				currNode->right = deleteNode(currNode->right , data);
				return currNode;
			}
			
			// The else case is invoked when the current Node is the element we want to delete.
			else{
				if(currNode->left == NULL){
					BinaryTreeNode<int>* temp = currNode->right;
					currNode->right = NULL;
					delete currNode;
					return temp;
				}else if(currNode->right == NULL){
					BinaryTreeNode<int>* temp = currNode->left;
					currNode->left = NULL;
					delete currNode;
					return temp;
				}else if(currNode->left == NULL && currNode->right == NULL){
					return NULL;
				}
				else{
					// This else case is invoked when the current node has a left and a right subtree present.
					// In this case we don't delete the root value, we replace it with the leftMax or rightMin.
					// In this implementation I have replaced the current Node with the rightMin.
					
					BinaryTreeNode<int>* rightMinNode = currNode->right;
					while(rightMinNode->left != NULL){
						rightMinNode = rightMinNode->left;
					}
					
					// Now when we have the minimum value, we will replace it with current Node value.
					currNode->data = rightMinNode->data;
					currNode->right = deleteData(currNode->right , rightMinNode->data);
					return currNode;
				}
			}
		}
	
	public:
		void deleteNode(int val){
			this->root = deleteData(root , val);
		}
		
	private:
		bool helperFunction(BinaryTreeNode<int>* currNode, int target){
			if(currNode == NULL){
				return false;
			}
			
			if(currNode->data == target){
				return true;
			}
			
			else if(target < currNode->data){
				// So we can call the function recursively on he left side.
				return helperFunction(currNode->left , target);
			}
			
			else{
				return helperFunction(currNode->right, target);
			}
			
			return false;
		} 
		
		
	public:
		// As this function takes only one parameter, we will make a private function to do the process in recursion.
		bool hasData(int target){
			return this->helperFunction(this->root , target);
		}
		
    private:
    	void printTree(BinaryTreeNode<int>* currNode){
            if(currNode == NULL){
                return;
            }
            
            cout << currNode->data << ":";
            if(currNode->left != NULL){
                cout << "L:" << currNode->left->data << ",";
                
            }
            
            if(currNode->right != NULL){
                cout << "R:" << currNode->right->data;
            }
            cout << endl;
            
            printTree(currNode->left);
            printTree(currNode->right);
        }
    
    public:
    	void print() { 
    		printTree(this->root);
    	}
};

int main(){
	
	
	return 0;
}

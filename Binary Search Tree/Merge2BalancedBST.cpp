/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorderTraversal(TreeNode<int>* root, vector<int>& in){
    if(root == NULL){
        return;
    }
    
    inorderTraversal(root->left , in);
    in.push_back(root->data);
    inorderTraversal(root->right , in);
    
    return;
}

vector<int> merge(vector<int> inorder1, vector<int> inorder2){
    
    int i = 0, j = 0;
    vector<int> output;
    while(i < inorder1.size() && j < inorder2.size()){
        if(inorder1[i] <= inorder2[j]){
            output.push_back(inorder1[i++]);
        }else{
            output.push_back(inorder2[j++]);
        }
    }
    
    while(i < inorder1.size()){
        output.push_back(inorder1[i++]);
    }
    
    while(j < inorder2.size()){
        output.push_back(inorder2[j++]);
    }
    
    return output;
}

TreeNode<int>* createSelfBalancedBST(int start, int end, vector<int> in){
    if(start > end){
        return NULL;
    }
    
    int mid = start + (end - start)/2;
    
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    
    root->left = createSelfBalancedBST(start , mid - 1, in);
    root->right = createSelfBalancedBST(mid + 1, end, in);
    
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // First step is too find the inorder traversal's of both the trees.
    vector<int> inorder1;
    vector<int> inorder2;
    
    inorderTraversal(root1 , inorder1);
    inorderTraversal(root2,  inorder2);
    
    // Now we will merge the 2 traversals to get a final inorder traversal.
    vector<int> finalInorder = merge(inorder1 , inorder2);
    
    // Final step is to create the final self balanced BST.
    TreeNode<int>* finalRoot = createSelfBalancedBST(0 , finalInorder.size()-1, finalInorder);
    
    return finalRoot;
    
}

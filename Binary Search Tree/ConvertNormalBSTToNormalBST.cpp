/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 // Approach:
 
 /*
 	1. We will first find the inorder traversal of the original BST.
 	2. When we get the elements in a sorted manner, we will create a new tree using the recursion.
 	3. At each recursion, the mid element will be the root, for left the range would be : (start, mid - 1)
 		and for right subtree the range would be (mid + 1, end).
 */
 
class Solution {
public:
    
    void inorderOfBST(TreeNode* root, vector<int>& res){
        if(root == NULL){
            return;
        }
        
        inorderOfBST(root->left , res);
        res.push_back(root->val);
        inorderOfBST(root->right ,res);
        
        return;
    }
    
    TreeNode* creatingSelfBalancedBST(int start, int end, vector<int> in){
        if(start > end){
            return NULL;
        }
        
        int mid = start + (end - start)/2;
        TreeNode* root = new TreeNode(in[mid]);
        
        root->left = creatingSelfBalancedBST(start , mid - 1, in);
        root->right = creatingSelfBalancedBST(mid + 1, end , in);
        
        return root;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        // First we need to find the inorder traversal of this bst.
        vector<int> in;
        inorderOfBST(root , in);
        
        // Next we will create a new BST using this inorder traversal and recursion.
        TreeNode* newRoot = creatingSelfBalancedBST(0 , in.size() - 1, in);
        
        return newRoot;
    }
};

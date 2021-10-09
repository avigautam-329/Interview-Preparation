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
class Solution {
public:
    
    int i = 0;
    
    TreeNode* helperFunction(vector<int>& preorder, int maximum = INT_MAX, int minimum = INT_MIN){
        if(i >= preorder.size()){
            return NULL;
        }
        
        // The first node will be the root.
        if(preorder[i] > maximum || preorder[i] < minimum){
            return NULL;
        }
        
        int rootValue = preorder[i];
        TreeNode* root = new TreeNode(rootValue);
        i++;
        
        root->left = helperFunction(preorder , root->val, minimum);
        root->right = helperFunction(preorder , maximum , root->val);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0){
            return NULL;
        }    
        
        
        TreeNode* root = helperFunction(preorder);
        return root;
    }
};

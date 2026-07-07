//The Real BST Rule

//For every node:

//All values in left subtree must be smaller than current node

//All values in right subtree must be greater than current node

//Not just immediate children.

class Solution {
public: 
     
     bool dfs(TreeNode* root, long long lo, long long hi){ 

        if(root == NULL)
          return true;

        if(root->val <= lo || root-> val >= hi)
          return false;

        return dfs(root->left, lo, root->val) 
               &&
               dfs(root->right, root->val, hi);
    
    }
     bool isValidBST(TreeNode* root) { 

        return dfs(root, LLONG_MIN, LLONG_MAX);
        
    }
};

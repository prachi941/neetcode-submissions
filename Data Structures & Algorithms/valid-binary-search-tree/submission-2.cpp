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


//interval based recursion
class Solution {
public:
    
    bool isValid(TreeNode* node, long long lower, long long upper){

        if(node == NULL){
            return true;
        }

        if(node->val <= lower || node->val >= upper){
            return false;
        }

        return isValid(node->left, lower, node->val)
            && isValid(node->right, node->val, upper);
    }


    bool isValidBST(TreeNode* root) {

        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};

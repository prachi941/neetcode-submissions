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


//For every node, there are 3 possibilities:
//Diameter lies entirely in the left subtree.
//Diameter lies entirely in the right subtree.
//Diameter passes through the current node.

class Solution {
public:

    int diameter = 0;

    int height(TreeNode* root) {

        if(root == NULL)
        return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);

    }

    int diameterOfBinaryTree(TreeNode* root) { 
        
        height(root);

        return diameter;
    }
};

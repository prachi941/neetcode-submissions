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

    int diameter = 0;

    int height(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);

        int curr_diameter = leftH + rightH;

        diameter = max(diameter, curr_diameter);

        return 1 + max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};

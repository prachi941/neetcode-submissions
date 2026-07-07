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

    int dfs(TreeNode* root, int maxSofar){

        if(root == NULL)
        return 0;

        int count = 0;

        if(root->val >= maxSofar)
        count = 1;

        maxSofar = max(maxSofar, root->val);

        count += dfs(root->left, maxSofar);
        count += dfs(root->right, maxSofar);

        return count;
    }

    int goodNodes(TreeNode* root) {

        return dfs(root, root -> val);
    }
};

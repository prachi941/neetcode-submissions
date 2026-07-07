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
    vector<vector<int>> levelOrder(TreeNode* root) { 

        vector<vector<int>> ans; // output list

        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root); // queue <-> .push()

        while(!q.empty()){ 

            int levelSize = q.size();

            vector<int> level;

            for(int i = 0; i < levelSize; i++){

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val); // vector <-> .push_back()

                if(node -> left)
                    q.push(node->left);
            

                if(node -> right)
                    q.push(node->right);
                
            }
             
             ans.push_back(level);
        } 

        return ans;
    }
};

class Solution {

    unordered_map<int, int> inMap;

public:

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);

        int inRoot = inMap[rootValue];
        int leftSize = inRoot - inStart;

        root->left = build(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           inRoot - 1);

        root->right = build(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            inRoot + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, inorder,
                     0, preorder.size() - 1,
                     0, inorder.size() - 1);
    }
};
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode *temp=root->right;
        root->right=root->left;
        root->left=temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};

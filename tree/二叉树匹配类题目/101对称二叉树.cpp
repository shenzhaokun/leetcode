class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)return true;
        return dfs(root->left,root->right);
    }
    bool dfs(TreeNode* A,TreeNode* B){
        if (!A&&!B)return true;
        if (!A||!B)return false;
        return (A->val==B->val)&&dfs(A->left,B->right)&&dfs(A->right,B->left);
    }
};

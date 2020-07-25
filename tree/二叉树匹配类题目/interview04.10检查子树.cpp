class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t1&&t2) return false;
        return dfs(t1,t2)||checkSubTree(t1->right,t2)||checkSubTree(t1->left,t2);
    }
    bool dfs(TreeNode *t1,TreeNode* t2){
        if(!t1&&!t2) return true;
        if(!t2||!t1) return false;
        return t1->val==t2->val&dfs(t1->left,t2->left)&&dfs(t1->right,t2->right);
    }
};

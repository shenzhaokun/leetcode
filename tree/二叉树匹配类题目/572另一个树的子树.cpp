class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t)return true;
        if(!s)return false;
        return dfs(s,t)||isSubtree(s->right,t)||isSubtree(s->left,t);
    }
    bool dfs(TreeNode *s, TreeNode* t){
        if(!s &&!t) return true;
        if(!s||!t) return false;
        return (s->val==t->val)&&dfs(s->left,t->left)&&dfs(s->right,t->right);
    }
};

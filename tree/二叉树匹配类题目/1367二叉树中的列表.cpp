class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head)return true;
        if(!root) return false; 
        return dfs(head,root)||isSubPath(head,root->left)||isSubPath(head,root->right); 
    }
    bool dfs(ListNode* A,TreeNode* B){
        if (!A) return true;
        if (!B) return false;
        return (A->val==B->val)&&(dfs(A->next,B->left)||dfs(A->next,B->right));
    }
};

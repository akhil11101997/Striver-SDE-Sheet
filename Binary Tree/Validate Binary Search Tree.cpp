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
    bool is(TreeNode* root,long maxi,long mini){
        if(root==NULL)
            return true;
        if(root->val>=maxi || root->val<=mini)
            return false;
        return is(root->left,(long)root->val,mini) && is(root->right,maxi,(long)root->val);
    }
    bool isValidBST(TreeNode* root) {
        
        return is(root,INT_MAX+1LL,INT_MIN-1LL);
    }
};

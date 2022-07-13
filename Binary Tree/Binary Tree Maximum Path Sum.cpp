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
    int maxPathHelper(TreeNode* root, int &res){
        if(root==NULL)
            return 0;
        int l=maxPathHelper(root->left,res);
        int r=maxPathHelper(root->right,res);
        res=max(res,root->val);
        res=max(res,root->val+max(l,r));
        res=max(res,root->val+l+r);
        if(l<0 && r<0)
            return root->val;
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        maxPathHelper(root,res);
        return res;
    }
};

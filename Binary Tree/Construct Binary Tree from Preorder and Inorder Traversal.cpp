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
    TreeNode* buildTreee(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int,int> &mp){
        if(prestart>preend || instart>inend)
            return NULL;
        int inroot=mp[preorder[prestart]];
        int numberInLeft=inroot-instart;
        TreeNode* root=new TreeNode(preorder[prestart]);
        root->left=buildTreee(preorder,prestart+1,prestart+numberInLeft,inorder,instart,inroot-1,mp);
        root->right=buildTreee(preorder,prestart+numberInLeft+1,preend,inorder,inroot+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return buildTreee(preorder,0,n-1,inorder,0,n-1,mp);
    }
};

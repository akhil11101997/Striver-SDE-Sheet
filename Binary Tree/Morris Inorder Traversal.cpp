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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* leftMostRight=curr->left;
                while(leftMostRight->right!=NULL && leftMostRight->right!=curr)
                    leftMostRight=leftMostRight->right;
                if(leftMostRight->right==curr){
                    leftMostRight->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
                else{
                    leftMostRight->right=curr;
                    curr=curr->left;
                }
            }
        }
        return res;
    }
};

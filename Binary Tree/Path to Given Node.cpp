/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool findPath(TreeNode* A, int B, vector<int> &res){
    if(A==NULL)
        return false;
    res.push_back(A->val);
    if(A->val==B){
        return true;
    }
    if(findPath(A->left,B,res)){
        return true;
    }
    if(findPath(A->right,B,res))
        return true;
    res.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    findPath(A,B,res);
    return res;
}

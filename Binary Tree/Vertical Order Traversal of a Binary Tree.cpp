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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            mp[x][y].insert(node->val);
            if(node->left!=NULL)
                q.push({node->left,{x-1,y+1}});
            if(node->right!=NULL)
                q.push({node->right,{x+1,y+1}});
        }
        for(auto a:mp){
            vector<int> temp;
            for(auto b:a.second){
                temp.insert(temp.end(),mp[a.first][b.first].begin(),mp[a.first][b.first].end());
            }
            res.push_back(temp);
        }
        return res;
    }
};

/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h> 
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> res;
    vector<int> in,pre,post;
    if(root==NULL)
        return res;
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root,1});
    while(!st.empty()){
        BinaryTreeNode<int> *node=st.top().first;
        int x=st.top().second;
        st.pop();
        if(x==1){
            pre.push_back(node->data);
            st.push({node,x+1});
            if(node->left!=NULL){
                st.push({node->left,1});
            }
        }
        else if(x==2){
            in.push_back(node->data);
            st.push({node,x+1});
            if(node->right!=NULL){
                st.push({node->right,1});
            }
        }
        else{
            post.push_back(node->data);
        }
        
    }
    res.push_back(in);
    res.push_back(pre);
    res.push_back(post);
    return res;
}

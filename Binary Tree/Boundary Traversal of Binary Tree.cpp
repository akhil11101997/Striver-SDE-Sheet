/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <stack> 
#
bool isLeaf(TreeNode<int>* root){
    if(root->left==NULL && root->right==NULL)
        return true;
    return false;
}
void addLeft(TreeNode<int>* root,vector<int> &res){
    if(root==NULL)
        return;
    if(!isLeaf(root))
        res.push_back(root->data);
    if(root->left!=NULL)
        addLeft(root->left,res);
    else
        addLeft(root->right,res);
    return;
}
void addRight(TreeNode<int>* root,stack<int> &st){
    if(root==NULL)
        return;
    if(!isLeaf(root))
        st.push(root->data);
    if(root->right!=NULL)
        addRight(root->right,st);
    else
        addRight(root->left,st);
    return;
}
void addLeaf(TreeNode<int>* root,vector<int> &res){
    if(root==NULL)
        return;
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    addLeaf(root->left,res);
    addLeaf(root->right,res);
    return;
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> res;
    if(root==NULL)
        return res;
    if(!isLeaf(root))
        res.push_back(root->data);
    addLeft(root->left,res);
    addLeaf(root,res);
    stack<int> st;
    addRight(root->right,st);
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

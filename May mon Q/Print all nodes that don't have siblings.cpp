void help(Node *root,vector<int> &ans){
    if(!root)return;
    if(root->left==NULL or root->right==NULL){
        if(root->left)ans.push_back(root->left->data);
        if(root->right)ans.push_back(root->right->data);
    }
    help(root->left,ans);
    help(root->right,ans);
}
vector<int> noSibling(Node* node)
{
    // code here
    vector<int> ans;
    help(node,ans);
    sort(ans.begin(),ans.end());
    if(ans.size()==0)return {-1};
    return ans;
}


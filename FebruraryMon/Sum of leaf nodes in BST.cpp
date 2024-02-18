class Solution
{
    public:
        /*You are required to complete below method */
        void dfs(Node * node, int &ans) {
            if(!node)
                return;
                
            if(!(node -> left) and !(node -> right))
                ans += node -> data;
            
            dfs(node -> left, ans);
            dfs(node -> right, ans);
        }
        
        int sumOfLeafNodes(Node *root ){
            int ans = 0;
            
            dfs(root, ans);
            return ans;
        }
};
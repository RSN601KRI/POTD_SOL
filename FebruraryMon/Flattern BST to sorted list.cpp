class Solution
{
public:
    Node *flattenBST(Node *root)
    {
        function<pair<Node*, Node*> (Node *, Node *, bool)> dfs = [&](Node * node, Node * prev, bool isLeft) -> pair<Node*, Node*> {
            if(!node)
                return {nullptr, nullptr};
                
            pair<Node *, Node *> left = dfs(node -> left, node, 1);
            pair<Node *, Node *> right = dfs(node -> right, node, 0);
                
            node -> left = left.first;
            node -> right = right.first;
            
            Node * MIN = left.first ? left.first : node;
            Node * MAX = right.second ? right.second : node;
            
            if(isLeft)
                MAX -> right = prev;
            
            node -> left = nullptr;
            return {MIN, MAX};
        };
        
        return dfs(root, nullptr, 0).first;
    }
};


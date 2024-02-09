/*struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        if(root == nullptr)
            return true; // Empty tree is considered to have leaves at same level
        
        queue<pair<Node*, int>> q;
        int leafLevel = -1; // Level of the first leaf node encountered
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            Node* node = current.first;
            int level = current.second;
            
            if(node->left == nullptr && node->right == nullptr) {
                if(leafLevel == -1)
                    leafLevel = level;
                else if(level != leafLevel)
                    return false; // Leaf nodes are not at the same level
            }
            
            if(node->left)
                q.push({node->left, level + 1});
            if(node->right)
                q.push({node->right, level + 1});
        }
        
        return true;
    }
};
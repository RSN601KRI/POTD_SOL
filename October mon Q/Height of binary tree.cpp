/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // Base case: if the node is NULL, the height is 0.
        if (node == NULL)
            return 0;
        
        // Recursively calculate the height of the left and right subtrees.
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // Return the maximum height of the left and right subtrees plus 1 (for the current node).
        return max(leftHeight, rightHeight) + 1;
    }
};
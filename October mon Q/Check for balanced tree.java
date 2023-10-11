/* struct Node
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

class Solution {
public:
    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // If the subtree is unbalanced, return -1
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        // Otherwise, return the height of the subtree
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(Node *root) {
        int result = height(root);
        // If the height is -1, the tree is unbalanced; otherwise, it is balanced.
        return (result != -1);
    }
};
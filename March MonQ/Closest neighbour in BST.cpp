/*
//Structure of the Node of the BST is as
struct Node {
    int key;
    Node* left, *right;
};


   'N' is the element
   'size' is the total element in BST
  */

class Solution {
  public:
    int findMaxForN(Node* root, int n) {
        // code here
        int maxValue = -1; // Initialize the maximum value found so far
        
        // Traverse the tree until we reach a leaf node or the key is equal to n
        while (root != nullptr) {
            // If the key of the current node is less than or equal to n
            // Update the maxValue and move to the right subtree
            if (root->key <= n) {
                maxValue = max(maxValue, root->key);
                root = root->right;
            } 
            // If the key of the current node is greater than n
            // Move to the left subtree
            else {
                root = root->left;
            }
        }
        
        return maxValue;
    }
};
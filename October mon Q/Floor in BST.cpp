class Solution{

public:
    int floor(Node* root, int x) {
        int floorValue = -1; // Initialize with a value not present in the tree
        
        while (root != nullptr) {
            if (root->data == x) {
                // If the current node's data is equal to x, x is the floor itself
                return x;
            } else if (root->data > x) {
                // If the current node's data is greater than x, move to the left subtree
                root = root->left;
            } else {
                // If the current node's data is less than x, update floorValue and move to the right subtree
                floorValue = root->data;
                root = root->right;
            }
        }
        
        return floorValue;
    }
};
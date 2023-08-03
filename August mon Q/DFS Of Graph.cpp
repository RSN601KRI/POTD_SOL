// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* inOrderSuccessor(Node* root, Node* x) {
        // Initialize the inorder successor variable to nullptr
        Node* successor = nullptr;

        // Start the traversal from the root
        while (root != nullptr) {
            // If the current node's value is greater than x's value,
            // update the successor and move to the left subtree
            if (root->data > x->data) {
                successor = root;
                root = root->left;
            } else {
                // If the current node's value is less than or equal to x's value,
                // move to the right subtree (since the inorder successor, if exists,
                // will be in the right subtree)
                root = root->right;
            }
        }

        return successor;
    }
};
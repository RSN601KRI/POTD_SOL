/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:

    void populateNext(Node *root) {
        // Initialize the previously visited node as NULL
        Node* prev = nullptr;

        // Helper function to perform inorder traversal
        inorderTraversal(root, prev);

        // After traversal, the next of the last node should be set to NULL
        if (prev != nullptr) {
            prev->next = nullptr;
        }
    }

    void inorderTraversal(Node* node, Node*& prev) {
        if (node == nullptr) {
            return;
        }

        // Traverse the left subtree
        inorderTraversal(node->left, prev);
        // Process the current node
        if (prev != nullptr) {
            prev->next = node;
        }
        prev = node;

        // Traverse the right subtree
        inorderTraversal(node->right, prev);
    }
};
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to do inorder traversal of the tree.
void inorder(Node* node) {
    if (node == NULL)
        return;

    inorder(node->left);   // Recursively traverse the left subtree.
    cout << node->data << " ";  // Print the data of the node.
    inorder(node->right);  // Recursively traverse the right subtree.
}

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if (node == NULL)
            return;

        // Recursively mirror the left and right subtrees.
        mirror(node->left);
        mirror(node->right);

        // Swap the left and right children.
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
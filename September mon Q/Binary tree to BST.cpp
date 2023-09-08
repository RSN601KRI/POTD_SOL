/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    // Function to perform inorder traversal of the binary tree and store elements in a vector.
    void inorderTraversal(Node *root, vector<int> &nodes) {
        if (root == nullptr) return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->data);
        inorderTraversal(root->right, nodes);
    }

    // Function to convert a sorted array to a BST.
    Node* sortedArrayToBST(vector<int> &nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        Node *newNode = new Node(nodes[mid]);
        newNode->left = sortedArrayToBST(nodes, start, mid - 1);
        newNode->right = sortedArrayToBST(nodes, mid + 1, end);
        return newNode;
    }

    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root) {
        vector<int> nodes;
        inorderTraversal(root, nodes); // Step 1
        sort(nodes.begin(), nodes.end()); // Step 2
        return sortedArrayToBST(nodes, 0, nodes.size() - 1); // Step 3
    }
};
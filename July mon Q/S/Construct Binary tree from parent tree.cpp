/* node structure  used in the program
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

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        int n = parent.size();
        if (n == 0) return NULL;

        vector<Node*> nodes(n, NULL);

        // Create all nodes
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node(i);
        }

        Node* root = NULL;

        // Set parent-child relationships
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                root = nodes[i];
            } else {
                Node* parentNode = nodes[parent[i]];
                if (!parentNode->left) {
                    parentNode->left = nodes[i];
                } else {
                    parentNode->right = nodes[i];
                }
            }
        }

        return root;
    }
};
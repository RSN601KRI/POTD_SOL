/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
    public:
    // function should print the nodes at k distance from root
   void dfs(Node* root, int k, int distance, vector<int>& result) {
        if (root == nullptr) return;

        // If the current node is at distance k, add its value to the result vector
        if (distance == k) {
            result.push_back(root->data);
            return;
        }

        // Continue traversing left and right subtrees with increased distance
        dfs(root->left, k, distance + 1, result);
        dfs(root->right, k, distance + 1, result);
    }

    // Function to print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int> result;
        dfs(root, k, 0, result); // Start DFS traversal from the root with initial distance 0
        return result;
    }
};
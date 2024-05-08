/*

Definition for Binary Tree Node
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

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> paths;
        vector<int> currentPath;
        findPaths(root, paths, currentPath);
        return paths;
    }

private:
    void findPaths(Node* node, vector<vector<int>>& paths, vector<int>& currentPath) {
        if (node == nullptr)
            return;

        // Add the current node's data to the current path
        currentPath.push_back(node->data);

        // If this is a leaf node, add the current path to the list of paths
        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(currentPath);
        } else {
            // Continue traversal to the left and right subtrees
            findPaths(node->left, paths, currentPath);
            findPaths(node->right, paths, currentPath);
        }

        // Backtrack: remove the current node's data from the current path
        currentPath.pop_back();
    }
};

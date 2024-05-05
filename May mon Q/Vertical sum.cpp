/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
  void verticalSumUtil(Node* root, int hd, map<int, int>& m) {
        if (root == nullptr)
            return;

        // Add current node's value to its vertical sum
        m[hd] += root->data;

        // Traverse left and right subtrees with updated horizontal distance
        verticalSumUtil(root->left, hd - 1, m);
        verticalSumUtil(root->right, hd + 1, m);
    }
    vector<int> verticalSum(Node* root) {
        vector<int> result;
        if (root == nullptr)
            return result;

        map<int, int> m; // Map to store vertical sums

        // Populate the map with vertical sums
        verticalSumUtil(root, 0, m);

        // Extract vertical sums from the map and store in the result vector
        for (auto it = m.begin(); it != m.end(); ++it) {
            result.push_back(it->second);
        }

        return result;
    }
};   
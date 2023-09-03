/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Helper function to check if two trees are isomorphic
    bool areIsomorphic(Node *root1, Node *root2) {
        // If both trees are empty, they are isomorphic
        if (root1 == NULL && root2 == NULL)
            return true;

        // If one of the trees is empty, they are not isomorphic
        if (root1 == NULL || root2 == NULL)
            return false;

        // Check if the current nodes have the same data
        if (root1->data != root2->data)
            return false;

        // Check for isomorphism with swapped children
        bool isomorphicWithSwap =
            (areIsomorphic(root1->left, root2->left) && areIsomorphic(root1->right, root2->right)) ||
            (areIsomorphic(root1->left, root2->right) && areIsomorphic(root1->right, root2->left));

        return isomorphicWithSwap;
    }

    // Return True if the given trees are isomorphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2) {
        return areIsomorphic(root1, root2);
    }
};

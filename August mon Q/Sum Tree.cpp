/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

bool checkSumTree(Node* node, int& sum) {
if (node == NULL) {
        sum = 0;
        return true;
    }
    
    // If the node is a leaf node, then it is a Sum Tree by definition
    if (node->left == NULL && node->right == NULL) {
        sum = node->data;
        return true;
    }

    int leftSum, rightSum;
    bool leftIsSumTree = checkSumTree(node->left, leftSum);
    bool rightIsSumTree = checkSumTree(node->right, rightSum);

    // Compute the sum of the subtree rooted at this node
    sum = leftSum + rightSum + node->data;
    
    // The current node is a Sum Tree if:
    // 1. The left subtree is a Sum Tree
    // 2. The right subtree is a Sum Tree
    // 3. The current node's value is equal to the sum of its left and right subtrees
    return (leftIsSumTree && rightIsSumTree && node->data == leftSum + rightSum);
}

class Solution {
  public:
    bool isSumTree(Node* root) {
        int sum;
        return checkSumTree(root, sum);
    }
};
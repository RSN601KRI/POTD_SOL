#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/
// Function to return a list containing elements of the left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> result;

    // Base case: if the tree is empty
    if (root == NULL)
        return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        // Traverse all nodes of the current level
        for (int i = 0; i < n; i++) {
            Node* current = q.front();
            q.pop();

            // If this is the first node of this level
            if (i == 0)
                result.push_back(current->data);

            // Enqueue left child
            if (current->left != NULL)
                q.push(current->left);

            // Enqueue right child
            if (current->right != NULL)
                q.push(current->right);
        }
    }

    return result;
}


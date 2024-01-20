/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
     int solve(Node *root, int &moves)
    {
        if(!root) return 0;
        int leftchild = solve(root->left, moves);
        int rightchild = solve(root->right, moves);
        
        moves += abs(leftchild) + abs(rightchild);
        return root->key - 1 + leftchild + rightchild;
    }
    int distributeCandy(Node* root)
    {
        int moves =0;
        solve(root, moves);
        return moves;
    }
};
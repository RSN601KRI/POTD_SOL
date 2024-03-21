/*Structure of the node of the binary tree is as
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
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result;
        // Base case
        if (root == NULL)
            return result;
        
        // Creating a queue for level order traversal
        queue<Node*> q;
        q.push(root);
        
        // Boolean variable to toggle the direction
        bool leftToRight = true;

        // Iterating through the tree level by level
        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel(size);
            
            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();

                // Deciding index based on direction
                int index = (leftToRight) ? i : size - 1 - i;

                // Storing node values in the current level vector
                currentLevel[index] = current->data;

                // Enqueuing left and right children if they exist
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            
            // Toggling the direction for the next level
            leftToRight = !leftToRight;
            
            // Appending the current level vector to the result
            result.insert(result.end(), currentLevel.begin(), currentLevel.end());
        }
        
        return result;
    }
};
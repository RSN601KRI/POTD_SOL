/* A binary tree Node

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


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      vector<int> result;
        if(root == NULL)
            return result;
        
        // Create a queue to store the nodes
        queue<Node*> q;
        q.push(root);
        
        // Loop until the queue is empty
        while(!q.empty())
        {
            // Get the front node in the queue
            Node* current = q.front();
            q.pop();
            
            // Process the current node (add its value to the result)
            result.push_back(current->data);
            
            // Enqueue the left child if it exists
            if(current->left != NULL)
                q.push(current->left);
            
            // Enqueue the right child if it exists
            if(current->right != NULL)
                q.push(current->right);
        }
        
        return result;
    }
};
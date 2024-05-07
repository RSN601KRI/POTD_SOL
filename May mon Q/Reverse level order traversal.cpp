/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> result;
    if (root == nullptr)
        return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> levelNodes;

        for (int i = 0; i < levelSize; ++i)
        {
            Node* curr = q.front();
            q.pop();
            levelNodes.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        result.insert(result.begin(), levelNodes.begin(), levelNodes.end());
    }

    return result;


}
/* Structure of a node is as follows */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void printCorner(Node *root)
{
    if (!root)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 1; i <= n; ++i) {
            Node* curr = q.front();
            q.pop();
            if (i == 1 || i == n) {
                cout << curr->data << " ";
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

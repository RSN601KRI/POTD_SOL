/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // Your code here
    if (!head) {
        root = NULL;
        return;
    }

    std::queue<TreeNode*> q;

    root = new TreeNode(head->data);
    q.push(root);
    head = head->next;

    while (head) {
        TreeNode* parent = q.front();
        q.pop();

        TreeNode* leftChild = NULL, *rightChild = NULL;
        
        leftChild = new TreeNode(head->data);
        q.push(leftChild);
        head = head->next;
        if (head) {
            rightChild = new TreeNode(head->data);
            q.push(rightChild);
            head = head->next;
        }

        parent->left = leftChild;
        parent->right = rightChild;
    }
}

// Helper function to perform level order traversal
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    std::cout << std::endl;
}

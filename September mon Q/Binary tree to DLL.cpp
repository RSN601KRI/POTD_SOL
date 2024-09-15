/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution {
  public:
  Node *head = NULL, *lastNode = NULL;
        void help(Node *root){
        if(!root)return;
        help(root->left);
        if(!head)head=root;
        if(lastNode)lastNode->right=root;
        root->left=lastNode;
        lastNode=root;
        help(root->right);
    }
    Node* bToDLL(Node* root) {
        // code here
        help(root);
        return head;
    }
};
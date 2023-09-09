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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        int ans;
        
        function<void(Node *)> find = [&](Node * cur) {
            if(cur == nullptr)
                return;
                
            find(cur -> right);
            
            --K;
            if(K == 0)
                ans = cur -> data;
                
            find(cur -> left);
        };
        
        find(root);
        
        return ans;
    }
};

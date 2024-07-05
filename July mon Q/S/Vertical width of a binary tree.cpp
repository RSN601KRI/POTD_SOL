class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        // code here
        if (!root) return 0;

        // Use a set to track unique horizontal distances.
        std::set<int> hdSet;
        
        // Queue to perform level order traversal. Pair contains node and its horizontal distance.
        std::queue<std::pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            Node* currentNode = front.first;
            int hd = front.second;
            
            // Add the horizontal distance to the set.
            hdSet.insert(hd);
            
            // Traverse the left child with hd - 1
            if (currentNode->left) {
                q.push({currentNode->left, hd - 1});
            }
            
            // Traverse the right child with hd + 1
            if (currentNode->right) {
                q.push({currentNode->right, hd + 1});
            }
        }
        
        // The size of the set gives the vertical width of the tree.
        return hdSet.size();
    }
};

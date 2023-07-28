class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class BST {
    // Function to find the lowest common ancestor in a BST.
    Node LCA(Node root, int n1, int n2) {
        if (root == null) {
            return null;
        }

        // If both n1 and n2 are less than the current node's data, then the LCA is in the left subtree.
        if (n1 < root.data && n2 < root.data) {
            return LCA(root.left, n1, n2);
        }

        // If both n1 and n2 are greater than the current node's data, then the LCA is in the right subtree.
        if (n1 > root.data && n2 > root.data) {
            return LCA(root.right, n1, n2);
        }

        // Otherwise, the current node is the LCA.
        return root;
    }
}
  
    

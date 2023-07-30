/*class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}*/

class Solution {

    // Function to find the inorder successor of the Node x in BST
    public Node inorderSuccessor(Node root, Node x) {
        // Case 1: If the right subtree of x is not null
        if (x.right != null) {
            return findLeftmostNode(x.right);
        }

        // Case 2: If the right subtree of x is null
        Node successor = null;
        while (root != null) {
            if (x.data < root.data) {
                successor = root;
                root = root.left;
            } else if (x.data > root.data) {
                root = root.right;
            } else {
                break;
            }
        }

        return successor;
    }

    // Helper function to find the leftmost node in a subtree
    private Node findLeftmostNode(Node node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }
}

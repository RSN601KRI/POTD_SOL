// Definition for a binary tree node
/*class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/
class Tree {

    // Function to find the median of a Binary Search Tree
    public static float findMedian(Node root) {
        // Step 1: Perform Inorder Traversal to get sorted elements
        List<Integer> sortedElements = new ArrayList<>();
        inorderTraversal(root, sortedElements);

        // Step 2: Calculate the median
        int n = sortedElements.size();
        if (n % 2 == 0) {
            int middleIdx1 = (n / 2) - 1;
            int middleIdx2 = n / 2;
            int median1 = sortedElements.get(middleIdx1);
            int median2 = sortedElements.get(middleIdx2);
            return (median1 + median2) / 2.0f;
        } else {
            int middleIdx = n / 2;
            return sortedElements.get(middleIdx);
        }
    }

    // Helper function for Inorder Traversal
    private static void inorderTraversal(Node root, List<Integer> sortedElements) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left, sortedElements);
        sortedElements.add(root.data);
        inorderTraversal(root.right, sortedElements);
    }

    public static void main(String[] args) {
        // Construct the BST
        Node root = new Node(6);
        root.left = new Node(3);
        root.right = new Node(8);
        root.left.left = new Node(1);
        root.left.right = new Node(4);
        root.right.left = new Node(7);
        root.right.right = new Node(9);

        // Find the median and print the result
        float median = findMedian(root);
        System.out.println("Median of the BST: " + median);
    }
}

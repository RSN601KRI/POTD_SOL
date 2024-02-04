public class Solution {
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    static ArrayList<Integer> boundaryTraversal(int matrix[][], int n, int m) {
        ArrayList<Integer> result = new ArrayList<>();

        if (n == 1) {
            for (int i = 0; i < m; i++) {
                result.add(matrix[0][i]);
            }
        } else if (m == 1) {
            for (int i = 0; i < n; i++) {
                result.add(matrix[i][0]);
            }
        } else {
            // Traverse the top row
            for (int i = 0; i < m; i++) {
                result.add(matrix[0][i]);
            }

            // Traverse the rightmost column
            for (int i = 1; i < n; i++) {
                result.add(matrix[i][m - 1]);
            }

            // Traverse the bottom row if there are more than 1 row
            if (n > 1) {
                for (int i = m - 2; i >= 0; i--) {
                    result.add(matrix[n - 1][i]);
                }
            }

            // Traverse the leftmost column if there are more than 1 column
            if (m > 1) {
                for (int i = n - 2; i >= 1; i--) {
                    result.add(matrix[i][0]);
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int n1 = 4, m1 = 4;
        int matrix1[][] = { { 1, 2, 3, 4 },
                { 5, 6, 7, 8 },
                { 9, 10, 11, 12 },
                { 13, 14, 15, 16 } };

        ArrayList<Integer> result1 = boundaryTraversal(matrix1, n1, m1);
        for (int num : result1) {
            System.out.print(num + " ");
        }
        System.out.println();

        int n2 = 3, m2 = 4;
        int matrix2[][] = { { 12, 11, 10, 9 },
                { 8, 7, 6, 5 },
                { 4, 3, 2, 1 } };

        ArrayList<Integer> result2 = boundaryTraversal(matrix2, n2, m2);
        for (int num : result2) {
            System.out.print(num + " ");
        }
        System.out.println();
    }}

    Boundary Traversal
    of Matrix{

}

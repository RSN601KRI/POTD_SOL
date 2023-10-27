class Solution {
    static int minimumNumberOfDeletions(String S) {
        int n = S.length();

        // Create a table to store the length of the longest palindromic subsequence.
        int[][] dp = new int[n][n];

        // Initialize the table for strings of length 1, which are always palindromes.
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Fill in the table for strings of length 2 and above.
        for (int cl = 2; cl <= n; cl++) {
            for (int i = 0; i < n - cl + 1; i++) {
                int j = i + cl - 1;
                if (S.charAt(i) == S.charAt(j) && cl == 2) {
                    dp[i][j] = 2;
                } else if (S.charAt(i) == S.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // The minimum number of deletions needed is the length of the string minus the
        // length of the longest palindromic subsequence.
        int minDeletions = n - dp[0][n - 1];
        return minDeletions;
    }

    public static void main(String[] args) {
        String S1 = "aebcbda";
        String S2 = "geeksforgeeks";

        int result1 = minimumNumberOfDeletions(S1);
        int result2 = minimumNumberOfDeletions(S2);

        System.out.println("Output 1: " + result1);
        System.out.println("Output 2: " + result2);
    }
}

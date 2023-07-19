class Solution {
    public int longestPalinSubseq(String S) {
        int n = S.length();
        int[][] dp = new int[n][n];
        
        // Initialize the dp[][] array
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill the dp[][] array
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (S.charAt(i) == S.charAt(j) && len == 2) {
                    dp[i][j] = 2;
                } else if (S.charAt(i) == S.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
}

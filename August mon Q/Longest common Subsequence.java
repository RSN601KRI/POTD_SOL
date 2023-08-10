class Solution
{
    // Function to find the length of the longest common subsequence in two strings.
    static int lcs(int x, int y, String s1, String s2)
    {
        int[][] dp = new int[x + 1][y + 1];

        // Initializing the first row and column with 0s.
        for (int i = 0; i <= x; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= y; j++)
            dp[0][j] = 0;

        // Filling up the dp array.
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // The last cell of the dp array contains the length of the LCS.
        return dp[x][y];
    }
}

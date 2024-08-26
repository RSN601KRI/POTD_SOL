class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        int n = pattern.length();
        int m = str.length();
        
        // DP table
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
        
        // Base case: Empty pattern matches empty string
        dp[0][0] = true;
        
        // Fill the first row (pattern vs empty string)
        for (int i = 1; i <= n; i++) {
            if (pattern[i-1] == '*') {
                dp[i][0] = dp[i-1][0];
            } else {
                dp[i][0] = false;
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern[i-1] == str[j-1] || pattern[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (pattern[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        // The answer is whether the entire pattern matches the entire string
        return dp[n][m] ? 1 : 0;
    }
};
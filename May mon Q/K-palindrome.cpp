class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (str[i] == str[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = min(dp[i+1][j] + 1, dp[i][j-1] + 1);
                }
            }
        }
        
        return dp[0][n-1] <= k ? 1 : 0;
    }
};
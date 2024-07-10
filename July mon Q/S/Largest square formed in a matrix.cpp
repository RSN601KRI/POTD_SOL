class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        if (n == 0 || m == 0) return 0;
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        int maxSquareSize = 0;
        
        // Fill the dp matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    maxSquareSize = std::max(maxSquareSize, dp[i][j]);
                }
            }
        }
        
        return maxSquareSize;
    }
};
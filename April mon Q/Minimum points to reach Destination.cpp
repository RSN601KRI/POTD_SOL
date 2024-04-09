#include <vector>
class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        
        // Start from the destination
        dp[m - 1][n - 1] = std::max(1, 1 - points[m - 1][n - 1]);
        
        // Fill the last column
        for (int i = m - 2; i >= 0; --i) {
            dp[i][n - 1] = std::max(1, dp[i + 1][n - 1] - points[i][n - 1]);
        }
        
        // Fill the last row
        for (int j = n - 2; j >= 0; --j) {
            dp[m - 1][j] = std::max(1, dp[m - 1][j + 1] - points[m - 1][j]);
        }
        
        // Fill the rest of the dp table
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                int min_points_on_exit = std::min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = std::max(1, min_points_on_exit - points[i][j]);
            }
        }
        
        return dp[0][0];
	} 
};
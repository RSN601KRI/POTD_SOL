#include <vector>

class Solution {
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        std::vector<long long> dp(n + 1);
        dp[0] = dp[1] = 1; // Base cases
        
        // Fill up the dp array using the recurrence relation
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};
class Solution {
  public:
    bool divisorGame(int n) {
        // code here
        std::vector<bool> dp(n + 1, false); // dp[i] represents whether Alice can win when starting with i stones
        
        // Base cases
        dp[2] = true; // If there are 2 stones, Alice can take 1 stone and Bob will have no more moves
        
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                // Check if j is a divisor of i and if Alice can win after Bob takes i - j stones
                if (i % j == 0 && !dp[i - j]) {
                    dp[i] = true; // Alice can win if she takes j stones
                    break; // no need to continue checking other divisors
                }
            }
        }
        
        return dp[n];
    }
};
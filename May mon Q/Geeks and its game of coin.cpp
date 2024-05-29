class Solution {
  public:
    int findWinner(int n, int x, int y) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0; // base case: no coins means a losing position for the player to move
        
        for (int i = 1; i <= n; ++i) {
            // check if Geek can make a move that leaves the opponent in a losing position
            if (i - 1 >= 0 && dp[i - 1] == 0) {
                dp[i] = 1;
            }
            if (i - x >= 0 && dp[i - x] == 0) {
                dp[i] = 1;
            }
            if (i - y >= 0 && dp[i - y] == 0) {
                dp[i] = 1;
            }
        }
        
        return dp[n];
    }
};
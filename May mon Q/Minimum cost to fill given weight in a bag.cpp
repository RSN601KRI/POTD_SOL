class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        std::vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            if (cost[i - 1] != -1) {
                for (int j = i; j <= w; ++j) {
                    if (dp[j - i] != INT_MAX) {
                        dp[j] = std::min(dp[j], dp[j - i] + cost[i - 1]);
                    }
                }
            }
        }
        
        return dp[w] == INT_MAX ? -1 : dp[w];
    }
};
class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        if (n == 0) return 0;
        
        // dp[i] will store the length of the longest subsequence ending with a[i]
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (abs(a[i] - a[j]) == 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // The answer is the maximum value in dp array
        return *max_element(dp.begin(), dp.end());
    }
};
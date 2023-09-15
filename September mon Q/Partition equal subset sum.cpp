
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        
        // If the sum of elements is odd, it cannot be divided into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }
        
        // Calculate the target sum for each subset
        int target = sum / 2;
        
        // Initialize a 2D DP array to store the subset sum possibilities
        vector<vector<bool>> dp(N + 1, vector<bool>(target + 1, false));
        
        // Base case: It's always possible to make a subset sum of 0 with an empty set
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
        
        // Fill the DP table
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= target; j++) {
                // If the current element is greater than the current sum, we can't include it
                if (arr[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Either include the current element or exclude it
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        
        // The last cell of the DP table will tell us if it's possible to partition the array
        return dp[N][target];
    }
};

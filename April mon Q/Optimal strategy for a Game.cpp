class Solution{
    public:
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        
        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = gap; j < n; i++, j++){
                // For one element, it is the value itself
                if(gap == 0) dp[i][j] = arr[i];
                // For two elements, it is the maximum of the two
                else if(gap == 1) dp[i][j] = max(arr[i], arr[j]);
                // For more than two elements, it is the maximum of either:
                // 1. Pick the first and solve for the remaining elements excluding first
                // 2. Pick the last and solve for the remaining elements excluding last
                else{
                    long long pickFirst = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                    long long pickLast = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                    dp[i][j] = max(pickFirst, pickLast);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
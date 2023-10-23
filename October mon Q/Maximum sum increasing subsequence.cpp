class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{ 
        // Create an array to store the maximum sum of increasing subsequences
        int dp[n];
        
        // Initialize the dp array with the values from the original array
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }
        
        // Calculate the maximum sum of increasing subsequences
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                    dp[i] = dp[j] + arr[i];
                }
            }
        }
        
        // Find the maximum value in the dp array
        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxSum) {
                maxSum = dp[i];
            }
        }
        
        return maxSum;
    }
};

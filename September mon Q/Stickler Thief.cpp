class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if (n == 0) // Handle the base case where there are no houses.
            return 0;
        if (n == 1) // If there's only one house, the thief can rob it.
            return arr[0];

        int dp[n]; // Create an array to store the maximum money for each house.

        // Initialize the dynamic programming array.
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]); // Choose the maximum between the first two houses.

        // Fill in the dynamic programming array.
        for (int i = 2; i < n; i++)
        {
            // The thief can either skip the current house or rob it.
            // If he robs it, add the current house's value to the value two houses ago.
            // If he skips it, take the maximum value from the previous house.
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }

        // The last element of dp[] will hold the maximum money.
        return dp[n - 1];
    }
};
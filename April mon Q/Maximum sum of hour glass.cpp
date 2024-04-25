class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
         if (n < 3 || m < 3) // Not enough rows or columns for an hourglass
            return -1;
        
        int maxSum = INT_MIN; // Initialize maxSum to the smallest possible integer
        
        for (int i = 0; i <= n - 3; ++i) { // Iterate over possible starting rows
            for (int j = 0; j <= m - 3; ++j) { // Iterate over possible starting columns
                int sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + // Top row
                          mat[i + 1][j + 1] +                         // Middle cell
                          mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2]; // Bottom row
                
                maxSum = max(maxSum, sum); // Update maxSum if the current sum is greater
            }
        }
        
        return maxSum;
    }
};
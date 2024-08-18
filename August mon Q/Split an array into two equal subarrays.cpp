class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int totalSum = 0;
        
        // Calculate the total sum of the array
        for (int num : arr) {
            totalSum += num;
        }
        
        // If total sum is odd, we cannot split it into two equal parts
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int targetSum = totalSum / 2;
        int prefixSum = 0;
        
        // Iterate through the array and calculate prefix sum
        for (int num : arr) {
            prefixSum += num;
            
            // If prefix sum equals the target sum, we can split the array
            if (prefixSum == targetSum) {
                return true;
            }
        }
        
        return false;
    }
};
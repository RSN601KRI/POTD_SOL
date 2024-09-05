class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        // Your code goes here
        // Calculate the sum of first n natural numbers
        int total_sum = n * (n + 1) / 2;
        
        // Calculate the sum of elements in the array
        int arr_sum = 0;
        for(int num : arr) {
            arr_sum += num;
        }
        
        // The missing number is the difference between the total sum and the array sum
        return total_sum - arr_sum;
    }
};
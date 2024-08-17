class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n = nums.size();
        std::vector<long long int> left(n, 1); // To store product of all elements to the left of nums[i]
        std::vector<long long int> right(n, 1); // To store product of all elements to the right of nums[i]
        std::vector<long long int> result(n);

        // Fill left array
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // Fill right array
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        // Fill result array where each element is product of left and right array
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};
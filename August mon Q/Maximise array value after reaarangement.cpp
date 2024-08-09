class Solution {
  public:
    int Maximize(vector<int> arr) {
        // Complete the function
        const int MOD = 1000000007; // 10^9 + 7
        
        // Sort the array in ascending order
        std::sort(arr.begin(), arr.end());
        
        int n = arr.size();
        long long result = 0;
        
        // Compute the sum of products
        for (int i = 0; i < n; ++i) {
            result = (result + (static_cast<long long>(arr[i]) * i) % MOD) % MOD;
        }
        
        return static_cast<int>(result);
    }
};
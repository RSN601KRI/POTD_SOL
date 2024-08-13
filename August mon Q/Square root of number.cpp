class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        if (n < 2) {
            return n; // Return n itself if it's 0 or 1
        }
        
        long long int left = 1, right = n, ans;
        
        while (left <= right) {
            long long int mid = left + (right - left) / 2;
            long long int midSquare = mid * mid;
            
            if (midSquare == n) {
                return mid; // Perfect square
            } else if (midSquare < n) {
                left = mid + 1;
                ans = mid; // Update answer when midSquare < n
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};
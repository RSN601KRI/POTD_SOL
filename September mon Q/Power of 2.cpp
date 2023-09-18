class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        // Check if n is greater than 0 and has only one bit set to 1.
        return n > 0 && (n & (n - 1)) == 0;
    }
};
   
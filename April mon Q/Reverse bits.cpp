class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
         uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1; // Left shift result to make space for the next bit
            result |= (x & 1); // Set the least significant bit of result to the least significant bit of x
            x >>= 1; // Right shift x to get the next bit
        }
        return result;
    }
};
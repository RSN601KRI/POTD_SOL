class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int lowerNibble = n & 0x0F; // Extract the lower nibble
        int upperNibble = n & 0xF0; // Extract the upper nibble
        int swappedNibbles = (lowerNibble << 4) | (upperNibble >> 4); // Swap and combine
        return swappedNibbles;
    }
};
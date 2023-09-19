class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Initialize a variable to store the position of the first set bit.
        unsigned int position = 1;
        
        // Iterate through the bits of the number.
        while (n > 0) {
            // Check if the current bit is set (i.e., equal to 1).
            if (n & 1) {
                return position; // If set, return the position.
            }
            
            // If not set, right-shift the number to check the next bit.
            n >>= 1;
            
            // Increment the position for the next bit.
            position++;
        }
        
        // If no set bit is found, return 0 (indicating no set bit found).
        return 0;
    }
};
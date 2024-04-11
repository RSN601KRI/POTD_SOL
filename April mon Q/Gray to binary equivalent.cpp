class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        int binary = 0;
        while (n > 0) {
            binary ^= n;
            n >>= 1;
        }
        return binary;
        
    }
};
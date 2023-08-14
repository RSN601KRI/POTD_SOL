class Solution
{
    public int[] singleNumber(int[] nums)
    {
        int xor = 0;
        
        // XOR of all elements in the array
        for (int num : nums) {
            xor ^= num;
        }
        
        // Find the rightmost set bit in XOR
        int rightmostSetBit = xor & -xor;
        
        int firstNum = 0;
        int secondNum = 0;
        
        // Divide the elements into two groups based on rightmost set bit
        for (int num : nums) {
            if ((num & rightmostSetBit) != 0) {
                firstNum ^= num;
            } else {
                secondNum ^= num;
            }
        }
        
        return new int[] { Math.min(firstNum, secondNum), Math.max(firstNum, secondNum) };
    }
}

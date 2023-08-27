class Solution
{
    public:
    string reverseWord(string str)
    {
        int left = 0;
        int right = str.length() - 1;
        
        while (left < right) {
            std::swap(str[left], str[right]);
            left++;
            right--;
        }
        
        return str;
    }
};
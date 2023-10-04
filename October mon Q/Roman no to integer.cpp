class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char, int> romanToInt;
        romanToInt['I'] = 1;
        romanToInt['V'] = 5;
        romanToInt['X'] = 10;
        romanToInt['L'] = 50;
        romanToInt['C'] = 100;
        romanToInt['D'] = 500;
        romanToInt['M'] = 1000;

        int decimalValue = 0;
        int prevValue = 0; // To keep track of the previous Roman numeral value

        for (int i = str.length() - 1; i >= 0; i--) {
            int current = romanToInt[str[i]];
            if (current < prevValue) {
                decimalValue -= current; // Subtract if current value is less than the previous
            } else {
                decimalValue += current; // Add if current value is greater than or equal to the previous
            }
            prevValue = current;
        }

        return decimalValue;
    }
};
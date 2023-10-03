class Solution {
public:
    string colName(long long int n) {
        string result = "";
        
        while (n > 0) {
            // Decrement n by 1 because A corresponds to 1, B corresponds to 2, and so on.
            n--;

            // Get the remainder when dividing by 26 to determine the current character.
            char currentChar = 'A' + n % 26;

            // Append the current character to the result.
            result = currentChar + result;

            // Update n to the quotient when dividing by 26.
            n /= 26;
        }

        return result;
    }
};

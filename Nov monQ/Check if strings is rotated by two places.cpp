class Solution {
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2) {
        int n = str1.length();

        // Check for clockwise rotation
        string clockwiseRotated = str1.substr(2) + str1.substr(0, 2);
        if (clockwiseRotated == str2) {
            return true;
        }

        // Check for anti-clockwise rotation
        string anticlockwiseRotated = str1.substr(n - 2) + str1.substr(0, n - 2);
        return anticlockwiseRotated == str2;
    }
};
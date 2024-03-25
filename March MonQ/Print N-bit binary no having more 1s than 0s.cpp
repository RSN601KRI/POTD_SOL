class Solution{
public:	
	void generateValidBinaryNumbers(int n, int ones, int zeros, string curr, vector<string>& result) {
        // Base case: if the length of the current binary number is n
        if (curr.length() == n) {
            result.push_back(curr); // Add the current binary number to the result
            return;
        }

        // If we can add more ones, try adding one
        if (ones < n) {
            generateValidBinaryNumbers(n, ones + 1, zeros, curr + "1", result);
        }

        // If we can add more zeros, try adding one only if we have more ones than zeros so far
        if (zeros < ones) {
            generateValidBinaryNumbers(n, ones, zeros + 1, curr + "0", result);
        }
    }

    vector<string> NBitBinary(int n) {
        vector<string> result;
        // Start the recursion with initial counts of ones and zeros as 0, and an empty string as the current binary number
        generateValidBinaryNumbers(n, 0, 0, "", result);
        return result;
    }
};
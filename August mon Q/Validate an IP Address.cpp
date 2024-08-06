/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // code here
        std::stringstream ss(str);
        std::string token;
        int count = 0;

        while (std::getline(ss, token, '.')) {
            // Check if token is empty or if it contains invalid characters
            if (token.empty() || !std::all_of(token.begin(), token.end(), ::isdigit)) {
                return 0;
            }

            // Convert the token to an integer
            int num = std::stoi(token);

            // Check if the integer is within the valid range for an IPv4 address
            if (num < 0 || num > 255) {
                return 0;
            }

            count++;
        }

        // Valid IPv4 address must have exactly four parts
        return count == 4 ? 1 : 0;
    }
};
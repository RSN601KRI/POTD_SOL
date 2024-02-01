class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        unordered_set<char> letters;

        // Traverse the input string and insert each character into the set.
        for (char ch : s) {
            if (isalpha(ch)) {
                letters.insert(tolower(ch));
            }
        }

        // Check if all letters of the alphabet are present in the set.
        return letters.size() == 26;
    }
};

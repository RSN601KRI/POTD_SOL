class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Check if the lengths of both strings are the same.
        if (s1.length() != s2.length()) {
            return false;
        }

        // Concatenate s1 with itself to check for rotations.
        std::string concatenated = s1 + s1;

        // Check if s2 is a substring of the concatenated string.
        if (concatenated.find(s2) != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }
};
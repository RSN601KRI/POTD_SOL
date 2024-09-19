class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
         vector<string> words;
        stringstream ss(str);
        string word;
        
        // Split the string by '.'
        while (getline(ss, word, '.')) {
            words.push_back(word);
        }
        
        // Reverse the vector of words
        reverse(words.begin(), words.end());
        
        // Join the reversed words with '.'
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += ".";
            }
        }
        
        return result;
    }
};
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		vector<string> result;
        string temp;
        generateSubsequences(s, 0, temp, result);
        sort(result.begin(), result.end());
        return result;
    }

private:
    void generateSubsequences(const string& s, int index, string& temp, vector<string>& result) {
        if (index == s.length()) {
            if (!temp.empty())
                result.push_back(temp);
            return;
        }

        // Exclude current character
        generateSubsequences(s, index + 1, temp, result);

        // Include current character
        temp.push_back(s[index]);
        generateSubsequences(s, index + 1, temp, result);

        // Backtrack
        temp.pop_back();
		}
};
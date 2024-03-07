class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
        vector<int> result;
        if (pattern.empty() || text.empty()) return result;

        vector<int> lps = computeLPS(pattern);
        int m = pattern.size();
        int n = text.size();
        int i = 0, j = 0;

        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j + 1);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return result;
    }

private:
    vector<int> computeLPS(string pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
};

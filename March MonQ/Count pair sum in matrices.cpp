class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    unordered_map<int, int> freq;

        // Count frequencies of elements in mat2
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                freq[mat2[i][j]]++;
            }
        }

        int countPairs = 0;

        // Check pairs in mat1 and mat2
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int complement = x - mat1[i][j];
                countPairs += freq[complement];
            }
        }

        return countPairs;
	}
};
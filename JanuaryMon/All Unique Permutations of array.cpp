class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> result;
        
        // Sort the array to ensure unique permutations
        sort(arr.begin(), arr.end());
        
        do {
            // Add the current permutation to the result
            result.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        
        return result;
    }
};
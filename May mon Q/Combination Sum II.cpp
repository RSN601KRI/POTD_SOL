class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>> result;
        vector<int> current;
        sort(arr.begin(), arr.end()); // Sort the array to handle duplicates
        backtrack(result, arr, current, 0, k);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, const vector<int>& arr, vector<int>& current, int start, int remain) {
        if (remain == 0) { // If the remaining sum is 0, add the current combination to the result
            result.push_back(current);
            return;
        }
        if (remain < 0) return; // If the remaining sum is negative, stop recursion

        for (int i = start; i < arr.size(); ++i) {
            // Skip duplicates
            if (i > start && arr[i] == arr[i - 1]) continue;

            // Add current element to the combination
            current.push_back(arr[i]);

            // Recursively find combinations with the remaining sum
            backtrack(result, arr, current, i + 1, remain - arr[i]);

            // Backtrack: remove the last element to try the next possible combination
            current.pop_back();
        }
    }
};
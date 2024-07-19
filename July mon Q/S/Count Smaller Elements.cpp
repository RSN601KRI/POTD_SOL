class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> result(n, 0);
        
        // Get the sorted array of unique elements
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());
        
        // Function to get the index of an element in the sorted array
        auto getIndex = [&sortedArr](int val) {
            return lower_bound(sortedArr.begin(), sortedArr.end(), val) - sortedArr.begin() + 1;
        };
        
        // Create a BIT/Fenwick Tree
        vector<int> BIT(sortedArr.size() + 1, 0);
        
        // Function to update the BIT
        auto update = [&BIT](int index, int value) {
            while (index < BIT.size()) {
                BIT[index] += value;
                index += index & (-index);
            }
        };
        
        // Function to get the prefix sum from the BIT
        auto query = [&BIT](int index) {
            int sum = 0;
            while (index > 0) {
                sum += BIT[index];
                index -= index & (-index);
            }
            return sum;
        };
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            int index = getIndex(arr[i]);
            result[i] = query(index - 1);
            update(index, 1);
        }
        
        return result;
    }
};
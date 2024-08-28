class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        // Step 1: Count frequencies of elements
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }
        
        // Step 2: Sort the array based on custom criteria
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (freqMap[a] == freqMap[b]) {
                return a < b; // If frequencies are the same, sort by element value
            }
            return freqMap[a] > freqMap[b]; // Otherwise, sort by frequency in descending order
        });
        
        return arr;
    }
};
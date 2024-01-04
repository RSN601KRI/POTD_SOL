class Solution {
    public:
      int singleElement(int arr[] ,int N) {
          // Create a hash map to store the frequency of each element
          std::unordered_map<int, int> freqMap;
  
          // Traverse the array and update the frequency in the hash map
          for (int i = 0; i < N; ++i) {
              freqMap[arr[i]]++;
          }
  
          // Traverse the hash map to find the element with frequency 1
          for (const auto& entry : freqMap) {
              if (entry.second == 1) {
                  return entry.first;
              }
          }
  
          // If no unique element is found, return -1 or any appropriate value
          return -1;
      }
};

#include <unordered_map>

class Solution
{
public:
    bool isFrequencyUnique(int n, int arr[])
    {
        // Create a frequency map to count the occurrences of each element
        std::unordered_map<int, int> frequencyMap;
        for (int i = 0; i < n; i++)
        {
            frequencyMap[arr[i]]++;
        }

        // Create a set to keep track of unique frequencies
        std::unordered_set<int> uniqueFrequencies;
        for (const auto &pair : frequencyMap)
        {
            int frequency = pair.second;
            if (uniqueFrequencies.count(frequency) > 0)
            {
                // Duplicate frequency found, return false
                return false;
            }
            uniqueFrequencies.insert(frequency);
        }

        // All frequencies are unique, return true
        return true;
    }
};
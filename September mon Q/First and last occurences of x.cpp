#include <vector>

class Solution
{
public:
    std::vector<int> find(int arr[], int n, int x)
    {
        int firstOccurrence = -1;
        int lastOccurrence = -1;

        // Binary search for the first occurrence
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                firstOccurrence = mid;
                right = mid - 1; // Continue searching in the left half
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // Binary search for the last occurrence
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                lastOccurrence = mid;
                left = mid + 1; // Continue searching in the right half
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // Check if x is found at least once
        if (firstOccurrence != -1)
        {
            return {firstOccurrence, lastOccurrence};
        }
        else
        {
            return {-1, -1}; // x is not found in the array
        }
    }
};

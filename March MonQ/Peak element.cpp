// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
        if (n == 1) // Only one element in the array
            return 0;
        if (arr[0] >= arr[1]) // First element is a peak if it's greater than or equal to the second element
            return 0;
        if (arr[n - 1] >= arr[n - 2]) // Last element is a peak if it's greater than or equal to the second last element
            return n - 1;
        
        // Iterate through the array
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) // If the current element is greater than or equal to its adjacent elements
                return i; // Return the index of the peak element
        }
        return -1; // If no peak element found
    }
};
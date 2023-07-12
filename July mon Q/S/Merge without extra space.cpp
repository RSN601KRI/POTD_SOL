class Solution {
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int i = n - 1; // Index of last element in arr1
        int j = 0;     // Index of first element in arr2
        int k = 0;     // Index of merged array (arr1 + arr2)

        // Rearrange the elements by comparing from the end of arr1 and the start of arr2.
        while (i >= 0 && j < m) {
            if (arr1[i] > arr2[j]) {
                // If the current element in arr1 is greater, swap and move to the next element.
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            } else {
                // If the current element in arr2 is greater, no need to swap, just move to the next element.
                break;
            }
        }

        // Sort the arrays individually (arr1 and arr2) after merging.
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
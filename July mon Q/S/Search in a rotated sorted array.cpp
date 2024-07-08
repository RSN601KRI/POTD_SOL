class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if the key is at the middle position
            if (arr[mid] == key) {
                return mid;
            }

            // Determine which part of the array is sorted
            if (arr[left] <= arr[mid]) {
                // Left part is sorted
                if (arr[left] <= key && key < arr[mid]) {
                    right = mid - 1;  // Key lies in the left part
                } else {
                    left = mid + 1;   // Key lies in the right part
                }
            } else {
                // Right part is sorted
                if (arr[mid] < key && key <= arr[right]) {
                    left = mid + 1;   // Key lies in the right part
                } else {
                    right = mid - 1;  // Key lies in the left part
                }
            }
        }

        // Key was not found
        return -1;
    }
};
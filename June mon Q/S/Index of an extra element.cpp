class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
         int left = 0, right = n - 2;  // arr2 is of size n-1
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If elements at mid index are the same in both arrays, extra element is in the right half
            if (arr1[mid] == arr2[mid]) {
                left = mid + 1;
            } else {
                // Otherwise, extra element is in the left half or at mid
                right = mid - 1;
            }
        }
        
        // After exiting the loop, left will be pointing to the extra element's index
        return left;
    }
};
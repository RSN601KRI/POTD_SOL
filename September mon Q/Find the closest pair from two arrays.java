class Solution{
    // Function for finding maximum and value pair
    public static ArrayList<Integer> printClosest (int arr[], int brr[], int n, int m, int x) {
        // Sort the second array
        Arrays.sort(brr);

        // Initialize variables to track the closest pair and minimum difference
        int diff = Integer.MAX_VALUE;
        int res_l = 0, res_r = 0; // Indices of the two elements in the closest pair

        // Traverse the first array
        for (int i = 0; i < n; i++) {
            // Use binary search to find the element in the second array closest to x - arr[i]
            int target = x - arr[i];
            int left = 0, right = m - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int currentDiff = Math.abs(brr[mid] - target);

                // Update the minimum difference and indices if a closer pair is found
                if (currentDiff < diff) {
                    diff = currentDiff;
                    res_l = i;
                    res_r = mid;
                }

                // If the current element is greater than the target, move to the left half
                if (brr[mid] > target) {
                    right = mid - 1;
                } 
                // If the current element is less than the target, move to the right half
                else {
                    left = mid + 1;
                }
            }
        }

        // Return the pair of elements that have the closest sum to x
        ArrayList<Integer> result = new ArrayList<>();
        result.add(arr[res_l]);
        result.add(brr[res_r]);
        return result;
    }
}

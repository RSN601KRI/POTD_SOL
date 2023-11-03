class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
        // Square all elements in the array
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * arr[i];
        }
        
        // Sort the array
        sort(arr, arr + n);

        // Fix the largest element and use two-pointer approach
        for (int i = n - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;
            
            while (left < right) {
                // If a Pythagorean triplet is found
                if (arr[left] + arr[right] == arr[i]) {
                    return true;
                }
                
                // If the sum is greater, move the right pointer to the left
                if (arr[left] + arr[right] < arr[i]) {
                    left++;
                } 
                // If the sum is smaller, move the left pointer to the right
                else {
                    right--;
                }
            }
        }
        
        // No Pythagorean triplet found
        return false;
    }
};

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if (n == 1) {
            return 1; // Special case when there's only one element.
        }

        long long totalSum = 0; // Variable to store the sum of all elements in the array.
        for (int i = 0; i < n; i++) {
            totalSum += a[i];
        }

        long long leftSum = 0; // Variable to store the sum of elements before the current index.
        for (int i = 0; i < n; i++) {
            // Calculate the sum of elements after the current index.
            long long rightSum = totalSum - leftSum - a[i];

            // Check if the left sum is equal to the right sum.
            if (leftSum == rightSum) {
                return i + 1; // Equilibrium point found at index i + 1.
            }

            // Update the left sum for the next iteration.
            leftSum += a[i];
        }

        return -1; // If no equilibrium point is found.
    }
};

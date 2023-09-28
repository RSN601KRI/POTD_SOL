class Solution {
    public static void convertToWave(int n, int[] a) {
        // Step 1: Sort the array in ascending order
        Arrays.sort(a);

        // Step 2: Swap adjacent elements alternately to create the wave pattern
        for (int i = 0; i < n - 1; i += 2) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }
}

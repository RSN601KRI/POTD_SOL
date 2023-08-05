//User function Template for Java

class Solution {
    public long findMinDiff(ArrayList<Integer> a, int n, int m) {
        // Sort the input ArrayList in ascending order.
        Collections.sort(a);

        // Initialize variables to keep track of minimum difference.
        long minDiff = Integer.MAX_VALUE;

        // Iterate over the ArrayList to find the minimum difference.
        for (int i = 0; i + m - 1 < n; ++i) {
            int currentDiff = a.get(i + m - 1) - a.get(i);
            minDiff = Math.min(minDiff, currentDiff);
        }

        return minDiff;
    }
}

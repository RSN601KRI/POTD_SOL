class Solution {
    static int splitArray(int[] arr , int N, int K) {
        int low = 0, high = 0;
        
        for (int i = 0; i < N; i++) {
            high += arr[i];
            low = Math.max(low, arr[i]);
        }
        
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isValid(arr, N, K, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
    
    static boolean isValid(int[] arr, int N, int K, int maxSum) {
        int splits = 1;
        int currentSum = 0;
        
        for (int i = 0; i < N; i++) {
            currentSum += arr[i];
            
            if (currentSum > maxSum) {
                splits++;
                currentSum = arr[i];
            }
        }
        
        return splits <= K;
    }
}


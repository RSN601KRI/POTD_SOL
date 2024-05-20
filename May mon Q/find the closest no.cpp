class Solution{
    public:
    // Method to compare which one is the more close. 
    // We find the closest by taking the difference 
    // between the target and both values. It assumes 
    // that val2 is greater than val1 and target lies 
    // between these two. 
    int getClosest(int val1, int val2, 
                   int k) 
    { 
        if (k - val1 >= val2 - k) 
            return val2; 
        else
            return val1; 
    }   
    // Returns element closest to target in arr[] 
    int findClosest(int n, int k,int arr[]) 
    { 
        // Corner cases 
        if (k <= arr[0]) 
            return arr[0]; 
        if (k >= arr[n - 1]) 
            return arr[n - 1]; 
      
        // Doing binary search 
        int i = 0, j = n, mid = 0; 
        while (i < j) { 
            mid = (i + j) / 2; 
      
            if (arr[mid] == k) 
                return arr[mid]; 
      
            /* If k is less than array element, 
                then search in left */
            if (k < arr[mid]) { 
      
                // If k is greater than previous 
                // to mid, return closest of two 
                if (mid > 0 && k > arr[mid - 1]) 
                    return getClosest(arr[mid - 1], 
                                      arr[mid], k); 
      
                /* Repeat for left half */
                j = mid; 
            } 
      
            // If l is greater than mid 
            else { 
                if (mid < n - 1 && k < arr[mid + 1]) 
                    return getClosest(arr[mid], 
                                      arr[mid + 1], k); 
                // update i 
                i = mid + 1;  
            } 
        } 
      
        // Only single element left after search 
        return arr[mid]; 
    } 
};
class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        int left = 0;
        int right = n - 1;
        int transitionIndex = -1;  // Initialize to -1 in case there's no transition point
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == 1) {
                transitionIndex = mid;
                right = mid - 1;  // Continue searching in the left half
            } else {
                left = mid + 1;  // Continue searching in the right half
            }
        }
        
        return transitionIndex;
    }
};
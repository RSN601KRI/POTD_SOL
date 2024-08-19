class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
         // Create a min-heap using a priority queue
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
        
        // Extract the minimum element k-1 times
        for(int i = 0; i < k - 1; i++) {
            minHeap.pop();
        }
        
        // The top element of the heap is now the k-th smallest element
        return minHeap.top();
    }
};
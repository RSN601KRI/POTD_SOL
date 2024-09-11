class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        // Using a priority queue (min-heap) to always connect the smallest ropes first.
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr.begin(), arr.end());

        long long totalCost = 0;

        // Continue combining ropes until only one remains.
        while (minHeap.size() > 1) {
            // Extract the two smallest ropes.
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();

            // The cost of connecting these two ropes.
            long long cost = first + second;
            totalCost += cost;

            // Push the resulting rope back into the heap.
            minHeap.push(cost);
        }

        return totalCost;
    }
};

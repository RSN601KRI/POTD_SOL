class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> ls(n, 0), rs(n, 0);
        stack<int> s;

        // Compute the left smaller array
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ls[i] = s.top();
            } else {
                ls[i] = 0;
            }
            s.push(arr[i]);
        }

        // Clear the stack for reuse
        while (!s.empty()) s.pop();

        // Compute the right smaller array
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                rs[i] = s.top();
            } else {
                rs[i] = 0;
            }
            s.push(arr[i]);
        }

        // Find the maximum difference
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(ls[i] - rs[i]));
        }

        return maxDiff;
    }
};
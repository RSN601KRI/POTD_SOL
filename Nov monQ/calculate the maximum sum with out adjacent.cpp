#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // calculate the maximum sum without adjacent
    int findMaxSum(int *arr, int n) {
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        // Create an array to store the maximum sum ending at each index
        int dp[n];

        // Initialize the first two elements
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        // Fill the dp array with the maximum sum ending at each index
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }

        // The result is the maximum sum ending at the last index
        return dp[n - 1];
    }
};

int main() {
    Solution obj;
    
    // Example 1
    int arr1[] = {5, 5, 10, 100, 10, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Output for Example 1: " << obj.findMaxSum(arr1, n1) << endl;

    // Example 2
    int arr2[] = {3, 2, 7, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Output for Example 2: " << obj.findMaxSum(arr2, n2) << endl;

    return 0;
}

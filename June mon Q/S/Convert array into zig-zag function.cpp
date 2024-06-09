class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        // code here
        for (int i = 0; i < n - 1; ++i) {
            if (i % 2 == 0) {
                // Even index, arr[i] should be less than arr[i+1]
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                }
            } else {
                // Odd index, arr[i] should be greater than arr[i+1]
                if (arr[i] < arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                }
            }
        }
    }
};
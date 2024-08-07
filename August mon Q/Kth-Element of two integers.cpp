class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
         int m = arr1.size();
        int n = arr2.size();
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                k--;
                if (k == 0) return arr1[i];
                i++;
            } else {
                k--;
                if (k == 0) return arr2[j];
                j++;
            }
        }

        while (i < m) {
            k--;
            if (k == 0) return arr1[i];
            i++;
        }

        while (j < n) {
            k--;
            if (k == 0) return arr2[j];
            j++;
        }

        return -1; // This line should not be reached if k is valid
    }
};
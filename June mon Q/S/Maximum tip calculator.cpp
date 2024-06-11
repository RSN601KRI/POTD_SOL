class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int, int>> diff; // To store the differences and their respective indices
        
        // Calculate the difference between arr and brr and store it along with the index
        for (int i = 0; i < n; ++i) {
            diff.push_back({abs(arr[i] - brr[i]), i});
        }
        
        // Sort the diff array based on the absolute difference in descending order
        sort(diff.rbegin(), diff.rend());
        
        long long totalTip = 0;
        int countA = 0, countB = 0;
        
        // Iterate over the sorted diff array
        for (int i = 0; i < n; ++i) {
            int index = diff[i].second;
            
            // Check who should take the order based on the tips and constraints
            if ((arr[index] >= brr[index] && countA < x) || countB == y) {
                totalTip += arr[index];
                countA++;
            } else {
                totalTip += brr[index];
                countB++;
            }
        }
        
        return totalTip;
    }
};
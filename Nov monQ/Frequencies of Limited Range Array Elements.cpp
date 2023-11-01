class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        // Initialize a frequency array with all elements set to 0.
        vector<int> freq(N, 0);

        // Count the frequency of each element in the input array.
        for (int i = 0; i < N; i++) {
            if (arr[i] <= N) {
                freq[arr[i] - 1]++;
            }
        }

        // Print the frequency of each element from 1 to N.
        for (int i = 0; i < N; i++) {
            if (i == P - 1) {
                // If P is out of bounds, print 0.
                cout << "0 ";
            } else {
                cout << freq[i] << " ";
            }
        }
    }
};

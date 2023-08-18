class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> result;
        int maxRight = a[n - 1]; // The rightmost element is always a leader
        result.push_back(maxRight);

        // Traverse the array from right to left
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] >= maxRight) {
                maxRight = a[i];
                result.push_back(maxRight);
            }
        }

        reverse(result.begin(), result.end()); // Reverse to get the correct order
        return result;
    }
};
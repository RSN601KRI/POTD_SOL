class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
        unordered_map<int, int> prefixSumCount;
        int sum = 0;
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            int remainder = (sum % k + k) % k; // Handling negative remainders

            if (remainder == 0) {
                maxLength = max(maxLength, i + 1);
            } else if (prefixSumCount.find(remainder) != prefixSumCount.end()) {
                maxLength = max(maxLength, i - prefixSumCount[remainder]);
            } else {
                prefixSumCount[remainder] = i;
            }
        }

        return maxLength;
    }
};